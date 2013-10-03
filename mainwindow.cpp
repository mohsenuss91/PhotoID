#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // hide minimize and maximize buttons.
    this->setWindowFlags(Qt::Tool | Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::CustomizeWindowHint);
    // Quit App when close the window.
    this->setAttribute(Qt::WA_QuitOnClose);
}

MainWindow::~MainWindow()
{
    delete ui;
}
