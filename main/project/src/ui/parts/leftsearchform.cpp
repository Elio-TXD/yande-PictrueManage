#include "leftsearchform.h"
#include "ui_leftsearchform.h"

LeftSearchForm::LeftSearchForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LeftSearchForm)
{
    ui->setupUi(this);
}

LeftSearchForm::~LeftSearchForm()
{
    delete ui;
}
