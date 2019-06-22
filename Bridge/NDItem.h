#pragma once
#include "Item.h"
class NDItem : public Item
{
	Q_OBJECT;
public:
	explicit NDItem(QGraphicsItem *parent = 0);
	//void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	void display();
	void change();
	QString getInfo();
private:
	QString unit;        //µ¥Î»
public slots:
	void setAttribute(QStringList info);
};