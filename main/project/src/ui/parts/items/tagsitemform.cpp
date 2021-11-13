#include "tagsitemform.h"
#include "ui_tagsitemform.h"

TagsItemForm::TagsItemForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TagsItemForm)
{
    ui->setupUi(this);
}

TagsItemForm::~TagsItemForm()
{
    delete ui;
}
