#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QtMultimediaWidgets>
#include <QVideoWidget>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileInfo>
#include <QAudioOutput>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    bool state = true;
    bool videoFileFlag ;
    bool audioFileFlag ;

    QMediaPlayer *videoPlayer ;
    QMediaPlayer *audioPlayer ;
    QVideoWidget *audioWidget ;


    ~MainWindow();


private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_actionopen_file_triggered();

    void on_pushButton_3_clicked();

    void changeEvent(QEvent* event);

    void on_pushButton_4_clicked();


private:
    Ui::MainWindow *ui;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;

};

#endif // MAINWINDOW_H
