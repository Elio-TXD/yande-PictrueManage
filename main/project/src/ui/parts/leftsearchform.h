#ifndef LEFTSEARCHFORM_H
#define LEFTSEARCHFORM_H

#include <QWidget>

namespace Ui {
class LeftSearchForm;
}

class LeftSearchForm : public QWidget
{
    Q_OBJECT

public:
    explicit LeftSearchForm(QWidget *parent = nullptr);
    ~LeftSearchForm();

private:
    Ui::LeftSearchForm *ui;
};

#endif // LEFTSEARCHFORM_H
