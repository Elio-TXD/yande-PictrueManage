#ifndef TAGSITEMFORM_H
#define TAGSITEMFORM_H

#include <QWidget>

namespace Ui {
class TagsItemForm;
}

class TagsItemForm : public QWidget
{
    Q_OBJECT

public:
    explicit TagsItemForm(QWidget *parent = nullptr);
    ~TagsItemForm();

private:
    Ui::TagsItemForm *ui;
};

#endif // TAGSITEMFORM_H
