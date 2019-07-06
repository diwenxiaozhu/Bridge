#pragma once
#include <QGraphicsRectItem>
#include <QGraphicsScene>


// �Զ��� Scene
class Scene : public QGraphicsScene
{
	Q_OBJECT
signals:
	void delWYsignal();

	void delNDsignal();

	void delYBsignal();
public:

protected:
	// ��������item  �Ҽ����Ƴ�item
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	//˫���޸�����
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	// Backspace���Ƴ�item
	void keyPressEvent(QKeyEvent *event);
};