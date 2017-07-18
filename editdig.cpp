#include "editdig.hpp"

editDig::editDig(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
	dw = new QDesktopWidget();
	//imglbl = new QLabel(this);
	table = new QTableWidget(this);

	table->setGeometry(0, 0, dw->geometry().width(), dw->geometry().height());
	QTableWidgetItem *thumbnail = new QTableWidgetItem();
	//	thumbnail->setData(Qt::DecorationRole, QPixmap("btn.PNG"));
	table->setShowGrid(true);
	table->verticalHeader()->hide();
	table->horizontalHeader()->hide();

	//	table->setRowCount(3);
		//table->setColumnCount(3);
		//table->setItem(0, 0, thumbnail);

		/*
		img.load("Blue.jpg");
		QPixmap *buf = new QPixmap();
		*buf = QPixmap::fromImage(img);

		imglbl->setPixmap(*buf);
		imglbl->setGeometry(0, 0, dw->geometry().width() / 3, dw->geometry().height() / 3);
		*/

	addImgItem();
	this->resize(dw->geometry().width() / 2, dw->geometry().height() / 2);
	this->show();

}

editDig::~editDig() {

}
void editDig::addImgItem() {
	int col = 0, row = 0, tem = 0;
	QDir dir = QDir("imgData");
	QFileInfoList list = dir.entryInfoList();

	for (int i = 0; i < list.size(); ++i) {
		QFileInfo fileInfo = list.at(i);

		std::string str = fileInfo.fileName().toStdString();
		if ((str.compare(".") == 0) || (str.compare("..") == 0))
			continue;
		if (fileInfo.isDir()) {
			row++;
			QFileInfoList list2 = QDir(fileInfo.filePath()).entryInfoList();
			tem = 0;
			for (int j = 0; j < list2.size(); j++) {
				QFileInfo info2 = list2.at(j);
				if (info2.isFile())
				{
					std::string str2 = info2.fileName().toStdString();
					tem++;
				}
			}
			if (col < tem)
				col = tem;
		}

	}
	table->setRowCount(row);
	table->setColumnCount(col);
	for(int u=1;u<row+1;u++)
	table->setRowHeight(row+1, dw->geometry().height()/(row+1));
	for (int u = 1; u<row + 1; u++)
	table->setColumnWidth(col+1, dw->geometry().width()/(col+1));


}