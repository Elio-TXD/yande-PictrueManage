#ifndef QSSMANAGER_H
#define QSSMANAGER_H

#include <QObject>

class QssManager : public QObject
{
    Q_OBJECT
public:
    explicit QssManager(QObject *parent = nullptr);

    void load(const QString &qss);

    void loadFile(const QString &file);

    static double scaleRatio();

private:

};

#endif // QSSMANAGER_H
