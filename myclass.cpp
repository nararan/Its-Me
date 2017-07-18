#include "myclass.h"
#include "editdig.hpp"

MyClass::MyClass(QWidget *parent)
	: QMainWindow(parent)
{
	QDesktopWidget * dw = new QDesktopWidget();
	ui.setupUi(this);
	vf = new QCameraViewfinder(ui.verticalLayoutWidget);
	ui.verticalLayout->addWidget(vf);
	this->resize(dw->geometry().width(), dw->geometry().height());

	foreach(QCameraInfo info, QCameraInfo::availableCameras())
	{
		cam = new QCamera(info);
	}
	cam->setViewfinder(vf);
	vf->resize(dw->geometry().width(), dw->geometry().height());
	ui.verticalLayoutWidget->resize(dw->geometry().width(), dw->geometry().height());
	cic = new QCameraImageCapture(cam);
	recorder = new QMediaRecorder(cam);
	connect(recorder, SIGNAL(stateChanged(QMediaRecorder::State)), this, SLOT(processImage(QMediaRecorder::State *)));
	cam->setCaptureMode(QCamera::CaptureVideo);


	auto&& settings = recorder->videoSettings();//6
	settings.setResolution(1280, 720);
	settings.setQuality(QMultimedia::VeryHighQuality);
	settings.setFrameRate(30.0);
	recorder->setVideoSettings(settings);

	cam->start();

}

MyClass::~MyClass()
{

}


void MyClass::newDig() {

	QString name = "aaa.mp4";
	recorder->setOutputLocation(QUrl::fromLocalFile(name));
	//shotDig mDig = new shotDig();
	if (ui.strBtn->text() == "start")
	{
		recorder->record();
		ui.strBtn->setText("save");
		cam->stop();

		///////////////////////////////////////////¿©±â¿¡  opencv Ä· 

	}
	else
	{
		QImage img;
		img.load("Blue.jpg");
		QPixmap *buf = new QPixmap();
		*buf = QPixmap::fromImage(img);

		QString name = QFileDialog::getSaveFileName(this, "save image", "untitle.png", "Images(*.png *.xpm *.jpg)");
		img.save(name);
	
	}
	 

}
void MyClass::newEdit() {
	editDig edit = new editDig();

}
void MyClass::reStart() {
	cam->start();
	ui.strBtn->setText("start");


}
void MyClass::processImage(QMediaRecorder::State *state)
{




	// sometime later, or on another press

	//shotDig mDig = new shotDig();

}



QImage  MyClass::Mat2QImage(cv::Mat const& src)
{
	cv::Mat temp; // make the same cv::Mat
	cvtColor(src, temp, CV_BGR2RGB); // cvtColor Makes a copt, that what i need
	QImage dest((const uchar *)temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
	dest.bits(); // enforce deep copy, see documentation 
				 // of QImage::QImage ( const uchar * data, int width, int height, Format format )
	return dest;
}