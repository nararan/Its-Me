#include "editdig.hpp"

editDig::editDig(QWidget * parent) : QWidget(parent) {
	dw = new QDesktopWidget();
	ui.setupUi(this);
	this->resize(dw->geometry().width(), dw->geometry().height());
	this->show();
}

editDig::~editDig() {
	
}
