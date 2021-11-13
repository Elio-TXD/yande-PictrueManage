#ifndef RIGHTSHOWFORM_H
#define RIGHTSHOWFORM_H

#include <QWidget>

namespace Ui {
class RightShowForm;
}

class RightShowForm : public QWidget
{
    Q_OBJECT

public:
    explicit RightShowForm(QWidget *parent = nullptr);
    ~RightShowForm();

private:
    Ui::RightShowForm *ui;
};

#endif // RIGHTSHOWFORM_H
