#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QByteArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->fileMaskLineEdit->setText("*.bin");
    ui->keyLineEdit->setText("1234567890ABCDEF");

    // Заполняем ComboBox
    ui->conflictComboBox->clear();
    ui->conflictComboBox->addItem("Перезаписывать файл");
    ui->conflictComboBox->addItem("Добавлять счётчик к имени");
    ui->conflictComboBox->setCurrentIndex(0);

    // Создаём поток и обработчик
    m_thread = new QThread(this);
    m_processor = new FileProcessor();

    m_processor->moveToThread(m_thread);

    // Подключаем сигналы от обработчика
    connect(m_processor, &FileProcessor::progressChanged, this, &MainWindow::onProgressChanged);
    connect(m_processor, &FileProcessor::statusChanged, this, &MainWindow::onStatusChanged);
    connect(m_processor, &FileProcessor::finished, this, &MainWindow::onFinished);
    connect(m_processor, &FileProcessor::errorOccurred, this, &MainWindow::onError);

    // Подключаем сигналы от потока
    connect(m_thread, &QThread::finished, m_processor, &QObject::deleteLater);

    m_thread->start();
    // Ручное подключение кнопок
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::on_startButton_clicked);
    connect(ui->pauseButton, &QPushButton::clicked, this, &MainWindow::on_pauseButton_clicked);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::on_stopButton_clicked);
}

MainWindow::~MainWindow()
{
    if (m_thread) {
        m_thread->quit();
        m_thread->wait();
    }
    delete ui;
}

void MainWindow::on_inputDirBrowseButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "Выберите папку для поиска файлов",
                                                    ui->inputDirLineEdit->text());
    if (!dir.isEmpty()) {
        ui->inputDirLineEdit->setText(dir);
    }
}

void MainWindow::on_outputDirBrowseButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "Выберите папку для сохранения результата",
                                                    ui->outputDirLineEdit->text());
    if (!dir.isEmpty()) {
        ui->outputDirLineEdit->setText(dir);
    }
}

void MainWindow::on_startButton_clicked()
{
    if (!m_processor) return;

    // Собираем настройки
    QString inputDir   = ui->inputDirLineEdit->text();
    QString outputDir  = ui->outputDirLineEdit->text();
    QString fileMask   = ui->fileMaskLineEdit->text();
    QString keyHex     = ui->keyLineEdit->text();
    bool deleteSource  = ui->deleteSourceCheckBox->isChecked();
    QString conflict   = ui->conflictComboBox->currentText();

    // Преобразуем hex-ключ в QByteArray
    QByteArray key = QByteArray::fromHex(keyHex.toLatin1());

    if (key.size() != 8) {
        QMessageBox::warning(this, "Ошибка", "Ключ должен быть ровно 8 байт (16 hex символов)");
        return;
    }

    m_processor->setSettings(inputDir, outputDir, fileMask, key, deleteSource, conflict);
    QMetaObject::invokeMethod(m_processor, "startProcessing", Qt::QueuedConnection);
}

void MainWindow::on_pauseButton_clicked()
{
    if (m_processor)
        QMetaObject::invokeMethod(m_processor, "pauseProcessing", Qt::QueuedConnection);
}

void MainWindow::on_stopButton_clicked()
{
    if (m_processor)
        QMetaObject::invokeMethod(m_processor, "stopProcessing", Qt::QueuedConnection);
}

void MainWindow::onProgressChanged(qint64 current, qint64 total, const QString &fileName)
{
    qDebug() << "Прогресс:" << current << "/" << total << fileName;
}

void MainWindow::onStatusChanged(const QString &status)
{
    qDebug() << "Статус:" << status;
}

void MainWindow::onFinished()
{
    qDebug() << "Обработка завершена";
}

void MainWindow::onError(const QString &error)
{
    QMessageBox::critical(this, "Ошибка", error);
}