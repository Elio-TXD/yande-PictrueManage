#ifndef SHOWITEMFORM_H
#define SHOWITEMFORM_H

#include <QWidget>

namespace Ui {
class ShowItemForm;
}

class ShowItemForm : public QWidget
{
    Q_OBJECT

public:
    explicit ShowItemForm(QWidget *parent = nullptr);
    ~ShowItemForm();

private:
    Ui::ShowItemForm *ui;
};

#endif // SHOWITEMFORM_H
