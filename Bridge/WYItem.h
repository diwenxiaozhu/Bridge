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
	double maxD;        //量程上限
	double minD;        //量程下限
public slots:
	void setAttribute(QStringList info);
};