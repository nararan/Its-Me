﻿#pragma once
#include "ui_editdig.h"
#include <QWidget>
#include <qdesktopwidget.h>
#include <qlabel.h>
#include <QTableWidget>
#include <qdir.h>
class editDig : public QWidget {
	Q_OBJECT

public:
	editDig(QWidget * parent = Q_NULLPTR);
	~editDig();
	QDesktopWidget *dw;
	QImage img;
	QLabel * imglbl;
	QTableWidget  * table;
	

	void addImgItem();

private:
	Ui::editDig ui;
};
