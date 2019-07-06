#pragma once
#include "Item.h"
#include <QString.h>

class YBItem : public Item
{
	Q_OBJECT;
public:
	explicit YBItem(QGraphicsItem *parent = 0);
	//�޸�����
	void change();
	//չʾ��ʷ����
	void display();
	//���ؽڵ���Ϣ
	QString getInfo();

private:
	double proWave;        //�������Ĳ���
public slots:
	//�޸����Բۺ���
	void setAttribute(QStringList info);
};