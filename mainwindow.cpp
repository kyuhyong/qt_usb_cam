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
