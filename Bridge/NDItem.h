#pragma once
#include "Item.h"
class NDItem : public Item
{
	Q_OBJECT;
public:
	explicit NDItem(QGraphicsItem *parent = 0);
	//���ƽڵ�����ͼ��
	void display();
	//�޸�����
	void change();
	//���ؽڵ���Ϣ
	QString getInfo();
private:
	QString unit;        //��λ
public slots:
	//�޸����Բۺ���
	void setAttribute(QStringList info);
};