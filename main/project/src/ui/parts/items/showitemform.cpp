#include "showitemform.h"
#include "ui_showitemform.h"

ShowItemForm::ShowItemForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowItemForm)
{
    ui->setupUi(this);
}

ShowItemForm::~ShowItemForm()
{
    delete ui;
}
