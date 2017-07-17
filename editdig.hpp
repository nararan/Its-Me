#pragma once
#include <QWidget>
#include "ui_editdig.h"
#include <qdesktopwidget.h>
class editDig : public QWidget {
	Q_OBJECT

public:
	editDig(QWidget * parent = Q_NULLPTR);
	~editDig();
	QDesktopWidget *dw;
	QImage img;

private:
	Ui::editDig ui;
};
