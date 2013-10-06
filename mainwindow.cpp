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

    // create instances.
    image = new Image(this);
    scene = new QGraphicsScene(this);

    // delete scrollbra of photoview.
    ui->photoView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->photoView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // create type photos.
    photo_35m_x_45mm = {1,"8idt 35mm X 45mm",344,443};
    photo_45m_x_45mm = {2,"8idt 45mm X 45mm",443,443};

    // set type photos.
    ui->typePhoto->addItem(photo_35m_x_45mm.Text);
    ui->typePhoto->addItem(photo_45m_x_45mm.Text);

    // change type of photos.
    QObject::connect(ui->typePhoto,SIGNAL(activated(int)),this,SLOT(changeTypePhoto(int)));

    // set scene to the view.
    ui->photoView->setScene(scene);

    // num of copies.
    ui->numPhotos->setValue(1);


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

// Load image.
void MainWindow::on_openButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,tr("Open File"),"",tr("Image Files (*.png *.jpg *.bmp)"));
    image->setRealPath(path);
    item = new QGraphicsPixmapItem(QPixmap(image->getRealPath()));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->clear();
    scene->addItem(item);
}

// zoom in the image.
void MainWindow::on_zoomIn_clicked() {
    ui->photoView->scale(1.2,1.2);
}

// zoom out the image.
void MainWindow::on_zoomOut_clicked() {
    ui->photoView->scale(1.0/1.2,1.0/1.2);
}

// rotate image 90°
void MainWindow::on_rotateRight_clicked() {
    ui->photoView->rotate(90);
}

// rotate image -90°
void MainWindow::on_rotateLeft_clicked() {
    ui->photoView->rotate(-90);
}

// rotate image 5°
void MainWindow::on_miniRotateRight_clicked() {
    ui->photoView->rotate(5);
}

// rotate image -5°
void MainWindow::on_miniRotateLeft_clicked() {
    ui->photoView->rotate(-5);
}
