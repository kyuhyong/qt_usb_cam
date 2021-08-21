#ifndef CAMERA_NODE_HPP
#define CAMERA_NODE_HPP

#include <QWidget>
#include <QThread>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QStringListModel>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <QImage>
//#include <opencv2/dnn.hpp>

#include "darknet.h"
#include <fstream>
#include <sstream>

#include <iostream>
using namespace std;
using namespace cv;

class Camera_Node : public QWidget
{
    Q_OBJECT
public:
    explicit Camera_Node(QWidget *parent = nullptr);
    bool init();
    void startStreaming();
    void stopStreaming();
    void set_capture_title(string &title);
    void set_caputre_count(int count);
    int  capture_image();
private slots:
    void on_update();

private:
    QPoint mPoint;
    QTimer *timer;
    cv::VideoCapture capture;
    cv::Mat frame;
    QImage qt_image;
    vector<string> classes;
    std::string  names_file;
    std::string  cfg_file;
    std::string  weights_file;
    std::string  capture_title;
    int          capture_count;
    //Detector detector;
    // Remove the bounding boxes with low confidence using non-maxima suppression
    void postprocess(Mat& frame, const vector<Mat>& out);
    // Draw the predicted bounding box
    void drawPred(int classId, float conf, int left, int top, int right, int bottom, Mat& frame);

Q_SIGNALS:
    void new_CameraImage(QImage qimage);

};

#endif // CAMERA_NODE_HPP
