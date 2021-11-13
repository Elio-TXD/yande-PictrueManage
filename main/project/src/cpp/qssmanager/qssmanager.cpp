#include "qssmanager.h"

#include <QWidget>
#include <QFile>
#include <QApplication>
#include <QScreen>

QssManager::QssManager(QObject *parent) : QObject(parent) {

}

void QssManager::load(const QString &qss) {
    QWidget *widget = dynamic_cast<QWidget*>(parent());
    if (widget) {
        widget->setStyleSheet(qss);
    }
}

void QssManager::loadFile(const QString &file) {
    QFile info(file);
    if (info.open(QFile::ReadOnly)) {
        load(info.readAll());
        info.close();
    }
}

double QssManager::scaleRatio() {
    return QApplication::primaryScreen()->logicalDotsPerInch() / 96;
}
