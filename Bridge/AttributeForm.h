#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_Attribute.h"

class AttributeForm : public QMainWindow
{
	Q_OBJECT
signals:
	void change(QStringList info);
public:
	AttributeForm(QWidget *parent = Q_NULLPTR);
	Ui::Form ui;


public slots:
	void change();
};