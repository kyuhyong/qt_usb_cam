#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&camera, SIGNAL(new_CameraImage(QImage)), this, SLOT(onNewCameraImage(QImage)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
/**
 * @brief MainWindow::onNewCameraImage
 * New Image captured from camera
 * @param qimage
 */
void MainWindow::onNewCameraImage(QImage qimage)
{
    ui->labelImage->setPixmap(QPixmap::fromImage(qimage));
    ui->labelImage->resize(ui->labelImage->pixmap()->size());
}

void MainWindow::on_buttonStartStreaming_clicked()
{
    camera.startStreaming();
}

void MainWindow::on_buttonCloseCamera_clicked()
{
    camera.stopStreaming();
}

void MainWindow::on_lineEdit_ImageTitle_textChanged(const QString &arg1)
{
    std::string utf8_text = arg1.toUtf8().constData();
    camera.set_capture_title(utf8_text);
}

void MainWindow::on_button_SetCount_clicked()
{
    int cntVal = ui->spinBox_ImageCount->value();
    std::cout<<"CNT = "<<cntVal<<std::endl;
    camera.set_caputre_count(cntVal);
}

void MainWindow::on_button_CaptureImage_clicked()
{
    int imgCnt = camera.capture_image();
    ui->spinBox_ImageCount->setValue(imgCnt);
}
