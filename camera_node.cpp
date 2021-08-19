#include "camera_node.hpp"


Camera_Node::Camera_Node(QWidget *parent) : QWidget (parent)
{
    setMouseTracking(true);
    timer = new QTimer(this);
    qDebug() << "Using CV Version: " << CV_MAJOR_VERSION << "." << CV_MINOR_VERSION;
    names_file = "/home/cto/workspace/video_capture/yolo/cfg/coco.names";
    cfg_file = "/home/cto/workspace/video_capture/yolo/cfg/yolov3-tiny.cfg";
    weights_file = "/home/cto/workspace/video_capture/yolo/weights/yolov3-tiny.weights";
}

bool Camera_Node::init() {
    return true;
}

void Camera_Node::on_update(){
    capture >> frame;
    cvtColor(frame, frame, CV_BGR2RGB);
    qt_image = QImage((const unsigned char*) (frame.data), frame.cols, frame.rows, QImage::Format_RGB888);
    Q_EMIT new_CameraImage(qt_image);
}

void Camera_Node::startStreaming(){
    capture.open(0);
    if (!capture.isOpened()){
        qDebug() << "Camera can't open";
        return;
    } else {
        qDebug() << "Starting Streaming";
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(on_update()));
        timer->start(20);
    }
}

void Camera_Node::stopStreaming(){
    disconnect(timer, SIGNAL(timeout()), this, SLOT(on_update()));
    capture.release();
    qDebug() << "Stop Streaming";
    timer->stop();
    cv::Mat image = cv::Mat::zeros(frame.size(),CV_8UC3);
    this->qt_image = QImage((const unsigned char*) (image.data), image.cols, image.rows, QImage::Format_RGB888);
    cout << "camera is closed" << endl;
}



