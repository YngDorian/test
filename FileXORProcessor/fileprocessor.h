#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <QObject>
#include <QString>
#include <QByteArray>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>

class FileProcessor : public QObject
{
    Q_OBJECT

public:
    explicit FileProcessor(QObject *parent = nullptr);
    ~FileProcessor();

    // ← вот этот метод был пропущен
    void setSettings(const QString &inputDir,
                     const QString &outputDir,
                     const QString &fileMask,
                     const QByteArray &key,
                     bool deleteSource,
                     const QString &conflictAction);

signals:
    void progressChanged(qint64 current, qint64 total, const QString &fileName);
    void statusChanged(const QString &status);
    void finished();
    void errorOccurred(const QString &error);

public slots:
    void startProcessing();
    void pauseProcessing();
    void resumeProcessing();
    void stopProcessing();

private:
    bool processFile(const QString &inputPath, const QString &outputPath);

    QString m_inputDir;
    QString m_outputDir;
    QString m_fileMask;
    QByteArray m_key;
    bool m_deleteSource = false;
    QString m_conflictAction;

    bool m_paused = false;
    bool m_stopped = false;
    QString generateOutputPath(const QString &originalFileName);
};

#endif // FILEPROCESSOR_H