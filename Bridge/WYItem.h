#pragma once
#include "Item.h"
class WYItem : public Item
{
	Q_OBJECT;
public:
	explicit WYItem(QGraphicsItem *parent = 0);
	//void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	void change();
	void display();
	QString getInfo();
private:
	double maxD;        //��������
	double minD;        //��������
public slots:
	void setAttribute(QStringList info);
};