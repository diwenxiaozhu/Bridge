#include "YBItem.h"
#include "QGraphicsSceneEvent"
#include "AttributeForm.h"
#include <qobject.h>
#include "qstring.h"
#include <QPainter>
#include <string>
#include <qfile.h>
#include <qmessagebox.h>
#include <qdebug.h>
#include "QFile"
#include "QMessageBox"
#include <QtCharts/QtCharts>
#include <QtCharts/QLineSeries>

// 自定义 Item
YBItem::YBItem(QGraphicsItem *parent)
	: Item(parent)
{
	//默认初始化 中心波长
	proWave = 0.0;
	//应变传感器默认为 红色
	setBrush(QBrush(Qt::red));
}



void YBItem::change() {
	AttributeForm *changeform = new AttributeForm();
	connect(changeform, SIGNAL(change(QStringList)), this, SLOT(setAttribute(QStringList)));
	changeform->ui.minLabel->hide();
	changeform->ui.maxLabel->hide();
	changeform->ui.minText->hide();
	changeform->ui.maxText->hide();
	changeform->ui.unitLabel->hide();
	changeform->ui.unitText->hide();

	changeform->ui.nameText->setText(getName());
	changeform->ui.modelText->setText(getModel());
	changeform->ui.produceText->setText(getProduce());
	changeform->ui.dateText->setText(getDate().toString("yyyy/MM/dd"));
	changeform->ui.proWaveText->setText(QString::number(proWave));

	changeform->setWindowFlags(changeform->windowFlags() | Qt::WindowStaysOnTopHint);
	changeform->show();
	
}

void YBItem::setAttribute(QStringList info) {
	qDebug() << info[0];
	setName(info[0]);
	setModel(info[1]);
	setProduce(info[2]);
	setDate(QDate::fromString(info[3], "yyyy/M/d"));
	qDebug() << info[4];
	proWave = info[4].toDouble();
}


QString YBItem::getInfo() {
	return QStringLiteral("传感器编号: ") + getName() + QStringLiteral("\n传感器型号: ") + getModel() + QStringLiteral("\n生产厂家: ")
		+ getProduce() + QStringLiteral("\n生产日期: ") + getDate().toString() + QStringLiteral("\n中心波长: ") + QString::number(proWave, 10, 5);
}

void YBItem::display() {
	// 打开文件
	QFile file(":/Bridge/yb2.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::question(NULL, "WARNINGS", "File ERROR", QMessageBox::Yes);
		return;
	}

	QStandardItemModel *model = new QStandardItemModel(10, 4);
	QTableView *tableview = new QTableView();
	tableview->setModel(model);
	model->setHeaderData(0, Qt::Horizontal, QObject::tr("Day"));
	model->setHeaderData(1, Qt::Horizontal, QObject::tr("Time"));
	model->setHeaderData(2, Qt::Horizontal, QObject::tr("Num"));
	model->setHeaderData(3, Qt::Horizontal, QObject::tr("Value"));
	QStandardItemModel *model1 = new QStandardItemModel(10, 4);
	QTableView *tableview1 = new QTableView();
	tableview1->setModel(model1);
	model1->setHeaderData(0, Qt::Horizontal, QObject::tr("Day"));
	model1->setHeaderData(1, Qt::Horizontal, QObject::tr("Time"));
	model1->setHeaderData(2, Qt::Horizontal, QObject::tr("Num"));
	model1->setHeaderData(3, Qt::Horizontal, QObject::tr("Value/us"));
	QLineSeries *series = new QLineSeries(); 
	QLineSeries *series1 = new QLineSeries();
	bool flag = false;
	int row = 0;
	int row1 = 0;
	while (!file.atEnd())
	{
		QByteArray line = file.readLine();
		QString str(line);
		//分割字符串
		QStringList list = str.split(" ");

		if (getName() == list[2]) {
			flag = true;
			//创立
			QDateTime tt;
			tt.setDate(QDate::fromString(list[0], "yyyy/MM/dd"));
			tt.setTime(QTime::fromString(list[1], "hh:mm:ss"));
			qDebug() << list[0] << list[1] << tt.date();
			//插入此数据
			series->append(tt.toMSecsSinceEpoch(), list[3].toDouble());
			model->insertRows(row, 1, QModelIndex());
			model->setData(model->index(row, 0, QModelIndex()), list[0]);
			model->setData(model->index(row, 1, QModelIndex()), list[1]);
			model->setData(model->index(row, 2, QModelIndex()), list[2]);
			model->setData(model->index(row, 3, QModelIndex()), list[3]);
			model1->insertRows(row1, 1, QModelIndex());
			int index = getName().toInt();
			double cul = list[3].toDouble();
			double result = 1000 * (cul - proWave) + 4;
			series1->append(tt.toMSecsSinceEpoch(), result);
			model1->setData(model1->index(row1, 0, QModelIndex()), list[0]);
			model1->setData(model1->index(row1, 1, QModelIndex()), list[1]);
			model1->setData(model1->index(row1, 2, QModelIndex()), list[2]);
			model1->setData(model1->index(row1, 3, QModelIndex()), result);
			row++;
			row1++;
		}
	}
	file.close();


	////chart
	//QChart *chart = new QChart();
	//// 将图例隐藏
	//chart->legend()->hide();
	//// 关联series，这一步很重要，必须要将series关联到QChart才能将数据渲染出来：
	//chart->addSeries(series);
	//// 开启OpenGL，QLineSeries支持GPU绘制，Qt其他有的图表类型是不支持的。
	//series->setUseOpenGL(true);
	//// 设置图表标题
	//chart->setTitle(QStringLiteral("部件数据"));

	////绑定X轴
	//QDateTimeAxis *axisX = new QDateTimeAxis;
	//axisX->setTickCount(1000);
	//axisX->setFormat("yyyy/MM/dd hh:mm:ss");
	//axisX->setTitleText("Date");
	//chart->addAxis(axisX, Qt::AlignBottom);
	//series->attachAxis(axisX);

	//QValueAxis *axisY = new QValueAxis;
	//axisY->setLabelFormat("%f");
	//axisY->setTitleText("value");
	//chart->addAxis(axisY, Qt::AlignLeft);
	//series->attachAxis(axisY);

	//QChartView *view = new QChartView(chart);
	//// 开启抗锯齿，让显示效果更好
	//view->setRenderHint(QPainter::Antialiasing);
	//view->resize(1000, 900);
	//// 显示图表
	//view->show();

	//chart
	QChart *chart1 = new QChart();
	// 将图例隐藏
	chart1->legend()->hide();
	// 关联series，这一步很重要，必须要将series关联到QChart才能将数据渲染出来：
	chart1->addSeries(series1);
	// 开启OpenGL，QLineSeries支持GPU绘制，Qt其他有的图表类型是不支持的。
	series1->setUseOpenGL(true);
	// 设置图表标题
	chart1->setTitle(QStringLiteral("部件数据(计算后)"));

	//绑定X轴
	QDateTimeAxis *axisX1 = new QDateTimeAxis;
	axisX1->setTickCount(1000);
	axisX1->setFormat("yyyy/MM/dd hh:mm:ss");
	axisX1->setTitleText("Date");
	chart1->addAxis(axisX1, Qt::AlignBottom);
	series1->attachAxis(axisX1);

	QValueAxis *axisY1 = new QValueAxis;
	axisY1->setLabelFormat("%f");
	axisY1->setTitleText("value");
	chart1->addAxis(axisY1, Qt::AlignLeft);
	series1->attachAxis(axisY1);

	QChartView *view1 = new QChartView(chart1);
	// 开启抗锯齿，让显示效果更好
	view1->setRenderHint(QPainter::Antialiasing);
	view1->resize(1000, 900);
	// 显示图表
	view1->show();

	tableview->setWindowTitle(QStringLiteral("应变检测器(计算前)"));
	tableview->resize(450, 350);
	tableview->show();

	tableview1->setWindowTitle(QStringLiteral("应变检测器(计算后)"));
	tableview1->resize(450, 350);
	tableview1->show();
}