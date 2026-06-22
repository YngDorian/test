#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "fileprocessor.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_inputDirBrowseButton_clicked();
    void on_outputDirBrowseButton_clicked();
    void on_startButton_clicked();
    void on_pauseButton_clicked();
    void on_stopButton_clicked();

    // Слоты для получения сигналов от FileProcessor
    void onProgressChanged(qint64 current, qint64 total, const QString &fileName);
    void onStatusChanged(const QString &status);
    void onFinished();
    void onError(const QString &error);

private:
    Ui::MainWindow *ui;

    QThread *m_thread = nullptr;
    FileProcessor *m_processor = nullptr;
};

#endif // MAINWINDOW_H