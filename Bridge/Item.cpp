#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "Item.h"
#include <QPen>
#include "QMessageBox"
#include <QFile>
#include <QDate>
#include <QtCharts/QtCharts>
#include <QtCharts/QLineSeries>

// 自定义 Item
Item::Item(QGraphicsItem *parent)
	: QGraphicsRectItem(parent), QObject(nullptr)
{
	//初始化属性
	setRect(10, 10, 10, 10);
	name = "null";
	model = "null";
	produce = "null";
	date = QDate::currentDate();

	// 可选择、可移动
	setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

void Item::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->button() == Qt::LeftButton) {
		if (event->modifiers() == Qt::ShiftModifier) {
			qDebug() << "Custom item left clicked with shift key.";
			// 选中 item
			setSelected(true);
		}
		else {
			qDebug() << "Custom item left clicked.";
			QGraphicsItem::mousePressEvent(event);
			event->accept();
		}
		emit select(getInfo());
	}
	else if (event->button() == Qt::RightButton) {
		qDebug() << "Custom item right clicked.";
		event->ignore();
	}
}

void Item::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
	if (event->modifiers() != Qt::AltModifier) {
		qDebug() << "Custom item moved.";
		QGraphicsItem::mouseMoveEvent(event);
		qDebug() << "moved" << pos();
	}
}

void Item::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if ((event->modifiers() == Qt::AltModifier) && m_bResizing) {
		m_bResizing = false;
	}
	else {
		QGraphicsItem::mouseReleaseEvent(event);
	}
}

void Item::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
	qDebug() << "Custom item double clicked.";
	change();
	event->accept();
}

void Item::change() {

}

int Item::type() const
{
	return UserType + 1;
}

void Item::display() {
	QFile file(":/Bridge/in.txt");
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::question(NULL, "WARNINGS", "File ERROR", QMessageBox::Yes);
		return;
	}

	QLineSeries *series = new QLineSeries();
	while (!file.atEnd())
	{
		QByteArray line = file.readLine();
		QString str(line);
		//分割字符串
		QStringList list = str.split(" ");
		//创立
		QDateTime tt;
		tt.setDate(QDate::fromString(list[0], "yyyy/MM/dd"));
		tt.setTime(QTime::fromString(list[1], "hh:mm:ss"));
		qDebug() << list[0] << list[1] << tt.date();
		//插入此数据
		series->append(tt.toMSecsSinceEpoch(), list[2].toDouble());
	}

	//chart
	QChart *chart = new QChart();
	// 将图例隐藏
	chart->legend()->hide();
	// 关联series，这一步很重要，必须要将series关联到QChart才能将数据渲染出来：
	chart->addSeries(series);
	// 开启OpenGL，QLineSeries支持GPU绘制，Qt其他有的图表类型是不支持的。
	series->setUseOpenGL(true);
	// 设置图表标题
	chart->setTitle(QStringLiteral("部件数据"));

	//绑定X轴
	QDateTimeAxis *axisX = new QDateTimeAxis;
	axisX->setTickCount(10);
	axisX->setFormat("yyyy/MM/dd");
	axisX->setTitleText("Date");
	chart->addAxis(axisX, Qt::AlignBottom);
	series->attachAxis(axisX);

	QValueAxis *axisY = new QValueAxis;
	axisY->setLabelFormat("%i");
	axisY->setTitleText("Sunspots count");
	chart->addAxis(axisY, Qt::AlignLeft);
	series->attachAxis(axisY);

	QChartView *view = new QChartView(chart);
	// 开启抗锯齿，让显示效果更好
	view->setRenderHint(QPainter::Antialiasing);
	view->resize(1000, 900);
	// 显示图表

	view->show();
	series->removePoints(0, 1);
	view->setAutoFillBackground(true);
	view->show();
	file.close();
}

QString Item::getName() {
	return name;
}

QString Item::getModel() {
	return model;
}

QString Item::getProduce() {
	return produce;
}

QDate Item::getDate() {
	return date;
}

void Item::setName(QString _name) {
	name = _name;
}

void Item::setModel(QString _Model) {
	model = _Model;
}

void Item::setProduce(QString _produce) {
	produce = _produce;
}

void Item::setDate(QDate _date) {
	date = _date;
}

QString Item::getInfo() {
	return "";
}