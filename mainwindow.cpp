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

    image = new Image(this);

    // create type photos.
    photo_35m_x_45mm = {1,"8idt 35mm X 45mm",344,443};
    photo_45m_x_45mm = {2,"8idt 45mm X 45mm",443,443};

    // set type photos.
    ui->typePhoto->addItem(photo_35m_x_45mm.Text);
    ui->typePhoto->addItem(photo_45m_x_45mm.Text);

    // change type of photos.
    QObject::connect(ui->typePhoto,SIGNAL(activated(int)),this,SLOT(changeTypePhoto(int)));
}

// it's runing when change type photo (slot).
void MainWindow::changeTypePhoto(int index) {
    if(index == 0) {
        ui->photoView->resize(photo_35m_x_45mm.Width,photo_35m_x_45mm.Height);
        ui->photoView->move(78,29);
    }

    if(index == 1) {
        ui->photoView->resize(photo_45m_x_45mm.Width,photo_45m_x_45mm.Height);
        ui->photoView->move(29,29);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
