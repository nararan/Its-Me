#include "editdig.hpp"
editDig::editDig(QWidget * parent) : QWidget(parent) {
	dw = new QDesktopWidget();
	ui.setupUi(this);
	this->resize(dw->geometry().width(), dw->geometry().height());

	img.load("Blue.jpg");
	QPixmap *buf = new QPixmap();
	*buf = QPixmap::fromImage(img);
	this->show();
}

editDig::~editDig() {

}
