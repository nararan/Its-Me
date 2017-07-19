#include "editdig.hpp"
#include <qgraphicsview.h>

editDig::editDig(QWidget * parent) : QWidget(parent) {
	ui.setupUi(this);
	ui.tableWidget = new QTableWidget(this);
	dw = new QDesktopWidget();
	width = dw->geometry().width() / 2;
	height = dw->geometry().height() / 2;

	ui.tableWidget->setShowGrid(false);
	ui.tableWidget->verticalHeader()->hide();
	ui.tableWidget->horizontalHeader()->hide();
	ui.tableWidget->setSizeAdjustPolicy(QTableWidget::AdjustToContents);

	addImgItem();
	this->resize(width, height);
	this->show();

}

editDig::~editDig() {

}
void editDig::addImgItem() {
	int col = 0, row = 0, tem = 0;
	QDir dir = QDir("imgData");
	QTableWidgetItem *thumbnail;
	QString str2[10][5];
	QFileInfoList list = dir.entryInfoList();

	for (int i = 0; i < list.size(); ++i) {
		QFileInfo fileInfo = list.at(i);

		std::string str = fileInfo.fileName().toStdString();
		if ((str.compare(".") == 0) || (str.compare("..") == 0))
			continue;
		if (fileInfo.isDir()) {
			QFileInfoList list2 = QDir(fileInfo.filePath()).entryInfoList();
			tem = 0;
			for (int j = 0; j < list2.size(); j++) {
				QFileInfo info2 = list2.at(j);
				if (info2.isFile())
				{
					str2[row][tem] = info2.filePath();
					tem++;
				}
			}
			row++;
			if (col < tem)
				col = tem;
		}

	}
	ui.tableWidget->setRowCount(row);
	ui.tableWidget->setColumnCount(col);

	for (int u = 0; u < row; u++)
		for (int t = 0; t < col; t++)
		{
			thumbnail = new QTableWidgetItem();
			thumbnail->setData(Qt::DecorationRole, QPixmap(str2[u][t]));
			ui.tableWidget->setItem(u, t, thumbnail);

		}


	for (int u = 0; u < row; u++)
		ui.tableWidget->setRowHeight(u, (height / row));

	for (int u = 0; u < row; u++)
		ui.tableWidget->setColumnWidth(u, (width / col));

}

void editDig::enterItem(QTableWidgetItem * item) {
	QGraphicsScene  *sc =new  QGraphicsScene( );
	QGraphicsView * grp=new QGraphicsView();
	grp->setScene(sc);
	QPixmap im=item->data(Qt::DecorationRole).value<QPixmap>();
	sc->addPixmap(im);
	grp->show();



}