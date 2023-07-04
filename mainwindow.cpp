#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //genral configs for mainWindow
    this->setStyleSheet("background-color:#D09CFA;");
    this->setWindowIcon(QIcon(":/icons/icons/stop.png"));
    this->setWindowTitle("Purple player");
    ui->actionopen_file->setIcon(QIcon(":/icons/icons/openfile.png"));



    videoPlayer = new QMediaPlayer();
    audioPlayer = new QMediaPlayer();
    videoWidget = new QVideoWidget();


    //notice that just one player can put his output in widget !
    videoPlayer->setVideoOutput(videoWidget);
    ui->verticalLayout->addWidget(videoWidget); //add videoWidget to layout


    //video plays in center of page
    centralWidget()->setLayout(ui->gridLayout);
    setCentralWidget(centralWidget());



    //pushbutton configs
    ui->pushButton_1->setIcon(QIcon(":/icons/icons/play.png"));
    ui->pushButton_1->setCursor(Qt::PointingHandCursor);
    ui->pushButton_1->setToolTip("play");
    ui->pushButton_2->setIcon(QIcon(":/icons/icons/pause.png"));
    ui->pushButton_2->setCursor(Qt::PointingHandCursor);
    ui->pushButton_2->setToolTip("pause");
    ui->pushButton_3->setIcon(QIcon(":/icons/icons/stop.png"));
    ui->pushButton_3->setCursor(Qt::PointingHandCursor);
    ui->pushButton_3->setToolTip("stop");
    ui->pushButton_4->setIcon(QIcon(":/icons/icons/fullScreen.svg"));
    ui->pushButton_4->setCursor(Qt::PointingHandCursor);
    ui->pushButton_4->setToolTip("full screen mode");



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionopen_file_triggered()
{
    videoPlayer->pause();
    audioPlayer->pause();

    //open file explorer to select file
    QString fileName = QFileDialog::getOpenFileName(this , "open file" , " " , "open file(*.*)");
    QFileInfo fileInfo(fileName);

        if (fileInfo.suffix() == "mp3") {
            audioFileFlag = true ;
            videoFileFlag = false ;
            // Play a specific video in the videoWidget
            videoPlayer->setMedia(QUrl("qrc:/videos/videos/video.mp4"));
            videoPlayer->play();

            //play Audio
            audioPlayer->setMedia(QUrl(fileName));
            audioPlayer->play();

        } else if(fileInfo.suffix() == "mkv" || fileInfo.suffix() == "mp4"){
            videoFileFlag = true ;
            audioFileFlag = false ;

            // Play the selected audio file
            videoPlayer->setMedia(QUrl(fileName));
            videoPlayer->play();

        } else if(audioFileFlag){
            audioPlayer->play();
            videoPlayer->play();

        } else if(videoFileFlag){
            videoPlayer->play();
        }
}



void MainWindow::on_pushButton_1_clicked()
{
    this->setWindowIcon(QIcon(":/icons/icons/play.png"));

    if (audioFileFlag) {
        videoPlayer->play();
        audioPlayer->play();
    }else{
        videoPlayer->play();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    this->setWindowIcon(QIcon(":/icons/icons/pause.png"));

    if (audioFileFlag) {
        videoPlayer->pause();
        audioPlayer->pause();
    }else{
        videoPlayer->pause();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    videoPlayer->stop();
    audioPlayer->stop();
}

void MainWindow::changeEvent(QEvent* event)
{

    if (event->type() == QEvent::WindowStateChange)
    {
        if (this->windowState().testFlag(Qt::WindowFullScreen))
        {
            this->setStyleSheet("background-color:black;");
            videoWidget->setStyleSheet("background-color:black;");
        }
        else {
            this->setStyleSheet("background-color:#D09CFA;");
        }
    }

    QMainWindow::changeEvent(event);
}

void MainWindow::on_pushButton_4_clicked()
{

    if (state) {
        this->showFullScreen();
        this->setStyleSheet("background-color:black;");
        videoWidget->setStyleSheet("background-color:black;");
        ui->pushButton_4->setIcon(QIcon(":/icons/icons/normalScreen.svg"));
        ui->pushButton_4->setToolTip("normal screen");

    }else {
        this->showNormal();
        this->setStyleSheet("background-color:#D09CFA;");
        ui->pushButton_4->setIcon(QIcon(":/icons/icons/fullScreen.svg"));
        ui->pushButton_4->setToolTip("full screen mode");
    }
    state = !state ;

}






