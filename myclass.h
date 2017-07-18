#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets/QMainWindow>
#include "opencv2/opencv.hpp"  
#include "ui_myclass.h"
#include <qcamera.h>
#include <QCameraImageCapture>
#include <QMessageBox>
#include <QCameraInfo>
#include <QLayout>
#include <QCameraViewfinder>
#include <QFileDialog>
#include <QPixmap>
#include <QImage>
#include <qvideoprobe.h>
#include <QMediaRecorder>
#include <time.h> 



class MyClass : public QMainWindow
{
	Q_OBJECT

public:
	MyClass(QWidget *parent = 0);
	~MyClass();
	QImage Mat2QImage(cv::Mat const& src);
	QCameraViewfinder * vf;

	QCamera * cam;

private:
	Ui::MyClassClass ui;

	public slots:
	void processImage(QMediaRecorder::State *state);
	void newDig();
	void newEdit();
	void reStart();
};

#endif // MYCLASS_H
