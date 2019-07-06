#pragma once
#include <QGraphicsRectItem>
#include <QGraphicsScene>


// ×Ô¶¨Òå Scene
class Scene : public QGraphicsScene
{
	Q_OBJECT
signals:
	void delWYsignal();

	void delNDsignal();

	void delYBsignal();
public:

protected:
	// ×ó¼ü£ºÌí¼Óitem  ÓÒ¼ü£ºÒÆ³ıitem
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	//Ë«»÷ĞŞ¸ÄÊôĞÔ
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	// Backspace¼üÒÆ³ıitem
	void keyPressEvent(QKeyEvent *event);
};