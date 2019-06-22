#include "AttributeForm.h"
#include "QMessageBox"

AttributeForm::AttributeForm(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(change()));
}

//change²Ûº¯Êý
void AttributeForm::change() {
	if (ui.nameText->text() == "" || ui.modelText->text() == "" || ui.produceText->text() == "" || ui.dateText->text() == "") {
		QMessageBox::question(NULL, "WARNING", "THE TEXT IS EMPTY", QMessageBox::Yes);
		return;
	}
	QStringList *info = new QStringList;
	info->append(ui.nameText->text());
	info->append(ui.modelText->text());
	info->append(ui.produceText->text());
	info->append(ui.dateText->text());
	if (ui.minText->text() != "")
		info->append(ui.minText->text());
	if (ui.maxText->text() != "")
		info->append(ui.maxText->text());
	if (ui.proWaveText->text() != "")
		info->append(ui.proWaveText->text());
	if (ui.unitText->text() != "")
		info->append(ui.unitText->text());
	emit change(*info);
	this->close();
}