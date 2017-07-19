#include "myclass.h"
#include "editdig.hpp"

using namespace cv;
using namespace std;

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
	cam->setCaptureMode(QCamera::CaptureVideo);
	cam->start();

}

MyClass::~MyClass()
{

}


void MyClass::newDig() {


	if (ui.strBtn->text() == "start")
	{
		ui.strBtn->setText("save");
		cam->stop();
		VideoCapture capture(0);
		VideoWriter outputVideo;
		Mat frame;
		capture >> frame;

		Size *s = new Size((int)frame.cols, (int)frame.rows);
		
		outputVideo.open("video.avi", -1,15, *s, true);

		if (!outputVideo.isOpened())
		{
			cout << "�������� �����ϱ� ���� �ʱ�ȭ �۾� �� ���� �߻�" << endl;
			return ;
		}

		if (!capture.isOpened())
		{
			cout << "��ķ�� ���� �����ϴ�." << endl;
			return ;
		}

		//ĸó ������ 640x480���� ����  
		capture.set(CAP_PROP_FRAME_WIDTH, 640);
		capture.set(CAP_PROP_FRAME_HEIGHT, 480);

		namedWindow("input", 1);
	
		while(1)
		{
			//��ĸ���κ��� �� �������� �о��  
			
		
			capture >> frame;
			outputVideo << frame;
		
			//ȭ�鿡 ������ ������
			imshow("input", frame);

			//ESCŰ ������ ����
			if (waitKey(1) == 27) break;

		}


		///////////////////////////////////////////���⿡  opencv ķ 

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