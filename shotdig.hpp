#pragma once
#include <QWidget>
#include "ui_shotdig.h"
#include <qdesktopwidget.h>
#include <qfiledialog.h>
class shotDig : public QWidget {
	Q_OBJECT

public:
	shotDig(QWidget * parent = Q_NULLPTR);
	~shotDig();
	QDesktopWidget *dw;
	QImage img;
private:
	Ui::shotDig ui;
	public slots:
	void saveImg();
	void editImg();
};
