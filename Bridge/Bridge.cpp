#include "Bridge.h"
#include <QMessageBox>
#include <QImage>
#include <QGraphicsItem>
#include <QPen>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QColorDialog>
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QtCharts/QtCharts>
#include "Scene.h"
#include "Item.h"
#include "YBItem.h"
#include "WYItem.h"
#include "NDItem.h"
#include "QMessageBox"
#include <QFile>
#include <QtCharts/QtCharts>
#include <QtCharts/QLineSeries>
#include "AttributeForm.h"
QT_CHARTS_USE_NAMESPACE


Bridge::Bridge(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//��������
	scene = new Scene();
	scene->setSceneRect(0,0,0,0);
	//����һ��Qpixmap ����ʼ������ͼƬ
	QPixmap *t = new QPixmap(":/Bridge/Resources/bridge.png");
	//��ͼƬ�󶨵�������
	scene->addPixmap(*t);
	//�������󶨵�GraphicsView��
	ui.bridgeImage->setScene(scene);
	//���ô�С
	ui.bridgeImage->resize(t->width(), t->height());

	ui.bridgeImage->show();
	//ȡ������
	ui.bridgeImage->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	ui.bridgeImage->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	connect(scene, SIGNAL(delNDsignal()), this, SLOT(delND()));
	connect(scene, SIGNAL(delWYsignal()), this, SLOT(delWY()));
	connect(scene, SIGNAL(delYBsignal()), this, SLOT(delYB()));
}

//����Ӷȴ������ۺ���
void Bridge::on_AddND_triggered() {
	ui.NDNum->setText(QString::number(ui.NDNum->text().toInt() + 1));
	NDItem *t = new NDItem;
	scene->addItem(t);
	connect(t, SIGNAL(select(QString)), this, SLOT(ItemSelect(QString)));
	QMessageBox::question(NULL, "Tip", "Add Successful", QMessageBox::Yes);
}

//���Ӧ�䴫�����ۺ���
void Bridge::on_AddYB_triggered() {
	ui.YBNum->setText(QString::number(ui.YBNum->text().toInt() + 1));
	YBItem *t = new YBItem;
	scene->addItem(t);
	connect(t, SIGNAL(select(QString)), this, SLOT(ItemSelect(QString)));
	QMessageBox::question(NULL, "Tip", "Add Successful", QMessageBox::Yes);
}

//���λ�ƴ������ۺ���
void Bridge::on_AddWY_triggered() {
	ui.WYNum->setText(QString::number(ui.WYNum->text().toInt() + 1));
	WYItem *t = new WYItem;
	scene->addItem(t);
	connect(t, SIGNAL(select(QString)), this, SLOT(ItemSelect(QString)));
	QMessageBox::question(NULL, "Tip", "Add Successful", QMessageBox::Yes);
}

//ɾ���Ӷȴ������ۺ���
void Bridge::delND() {
	ui.NDNum->setText(QString::number(ui.NDNum->text().toInt() - 1));
}

//ɾ��λ�ƴ������ۺ���
void Bridge::delWY() {
	ui.WYNum->setText(QString::number(ui.WYNum->text().toInt() - 1));
}

//ɾ��Ӧ�䴫�����ۺ���
void Bridge::delYB() {
	qDebug() << "121212121";
	ui.YBNum->setText(QString::number(ui.YBNum->text().toInt() - 1));
}

//��������ѡ�в�������
void Bridge::ItemSelect(QString info) 
{
	ui.Info->setText(info);
}

//��������Qt�ۺ���
void Bridge::on_actionQT_triggered()
{
	QMessageBox::aboutQt(this, tr("����Qt"));
}

//�����������߲ۺ���
void Bridge::on_actionAuthor_triggered()
{
	QMessageBox box;
	//QStringLiteral ���������ַ���
	box.setWindowTitle(QStringLiteral("��������"));
	box.setIcon(QMessageBox::Information);
	box.setText(QStringLiteral("����: ��� �����\nѧУ: ���콻ͨ��ѧ"));
	box.addButton(QStringLiteral("ȷ��"), QMessageBox::AcceptRole);
	if (box.exec() == QMessageBox::Accepted)
		box.close();
}