#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "camera_node.hpp"

#include <iostream>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonStartStreaming_clicked();
    void on_buttonCloseCamera_clicked();
    void onNewCameraImage(QImage qimage);

private:
    Ui::MainWindow *ui;
    Camera_Node camera;

};

#endif // MAINWINDOW_H
