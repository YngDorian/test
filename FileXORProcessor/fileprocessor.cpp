#include "fileprocessor.h"
#include <QThread>
#include <QDebug>

FileProcessor::FileProcessor(QObject *parent)
    : QObject(parent)
{
}

FileProcessor::~FileProcessor()
{
}

void FileProcessor::setSettings(const QString &inputDir,
                                const QString &outputDir,
                                const QString &fileMask,
                                const QByteArray &key,
                                bool deleteSource,
                                const QString &conflictAction)
{
    m_inputDir = inputDir;
    m_outputDir = outputDir;
    m_fileMask = fileMask;
    m_key = key;
    m_deleteSource = deleteSource;
    m_conflictAction = conflictAction;
}

QString FileProcessor::generateOutputPath(const QString &originalFileName)
{
    QString baseName = QFileInfo(originalFileName).completeBaseName();
    QString suffix   = QFileInfo(originalFileName).suffix();
    QString path     = m_outputDir + "/" + originalFileName;

    if (m_conflictAction.contains("счётчик", Qt::CaseInsensitive)) {
        int counter = 1;
        while (QFile::exists(path)) {
            QString newName = QString("%1_%2.%3")
            .arg(baseName)
                .arg(counter)
                .arg(suffix);
            path = m_outputDir + "/" + newName;
            counter++;
        }
    }
    return path;
}

void FileProcessor::startProcessing()
{
    m_stopped = false;
    m_paused = false;

    emit statusChanged("Сканируем папку...");

    QDir dir(m_inputDir);
    QStringList filters { m_fileMask };
    QFileInfoList files = dir.entryInfoList(filters, QDir::Files);

    if (files.isEmpty()) {
        emit statusChanged("Файлы не найдены");
        emit finished();
        return;
    }

    emit statusChanged(QString("Найдено файлов: %1").arg(files.size()));

    for (const QFileInfo &fileInfo : files) {
        if (m_stopped) break;

        QString inputPath = fileInfo.absoluteFilePath();
        QString fileName = fileInfo.fileName();
        QString outputPath = generateOutputPath(fileName);

        emit statusChanged("Обрабатываем: " + fileName);

        if (!processFile(inputPath, outputPath)) {
            emit errorOccurred("Ошибка при обработке: " + fileName);
            break;
        }

        if (m_deleteSource && !m_stopped) {
            QFile::remove(inputPath);
        }
    }

    if (!m_stopped)
        emit statusChanged("Обработка завершена");

    emit finished();
}

void FileProcessor::pauseProcessing()
{
    m_paused = true;
    emit statusChanged("Пауза");
}

void FileProcessor::resumeProcessing()
{
    m_paused = false;
    emit statusChanged("Продолжаем работу");
}

void FileProcessor::stopProcessing()
{
    m_stopped = true;
    m_paused = false;
}

bool FileProcessor::processFile(const QString &inputPath, const QString &outputPath)
{
    QFile inputFile(inputPath);
    QFile outputFile(outputPath);

    if (!inputFile.open(QIODevice::ReadOnly)) return false;
    if (!outputFile.open(QIODevice::WriteOnly)) return false;

    const qint64 chunkSize = 4 * 1024 * 1024; // 4 МБ
    qint64 fileSize = inputFile.size();
    qint64 processed = 0;

    while (!inputFile.atEnd() && !m_stopped) {
        while (m_paused && !m_stopped) {
            QThread::msleep(50);
        }

        QByteArray chunk = inputFile.read(chunkSize);

        for (int i = 0; i < chunk.size(); ++i) {
            chunk[i] = chunk[i] ^ m_key[i % m_key.size()];
        }

        outputFile.write(chunk);
        processed += chunk.size();

        emit progressChanged(processed, fileSize, QFileInfo(inputPath).fileName());
    }

    inputFile.close();
    outputFile.close();
    return true;
}