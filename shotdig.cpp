#include "shotdig.hpp"
#include "editdig.hpp"
shotDig::shotDig(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
	dw = new QDesktopWidget();

	img.load("Blue.jpg");
	QPixmap *buf = new QPixmap();
	*buf = QPixmap::fromImage(img);

	ui.imgLbl->setPixmap(*buf);
	ui.imgLbl->setGeometry(0, 0, dw->geometry().width(), dw->geometry().height());
	this->show();
}

shotDig::~shotDig() {

}
void  shotDig::saveImg() {
	QString name = QFileDialog::getSaveFileName();
	img.save(name);
}
void shotDig::editImg() {
	editDig edit = new editDig();

}

