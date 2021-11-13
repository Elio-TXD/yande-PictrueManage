#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qssmanager/qssmanager.h"
#include "filereader/filereader.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("[Yande.re]Reader");
    QssManager *qss = new QssManager(this);
#if _NDEBUG
    qss->loadFile("../../resourse/qss/mainwindow.css");
#else
    qss->loadFile(":/qss/mainwindow.css");
#endif

    initUI();

    FileReader reader;
    reader.loadAllFiles("E:/我的图片");
    reader.loadAllTags();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI() {
    ui->widget_title->setVisible(false);
}
