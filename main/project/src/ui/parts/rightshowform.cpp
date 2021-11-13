#include "rightshowform.h"
#include "ui_rightshowform.h"

RightShowForm::RightShowForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RightShowForm)
{
    ui->setupUi(this);
}

RightShowForm::~RightShowForm()
{
    delete ui;
}
