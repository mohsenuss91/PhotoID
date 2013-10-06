#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "image.h"
#include "photoType.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected slots:
    void changeTypePhoto(int index);
private slots:
    void on_openButton_clicked();

    void on_zoomIn_clicked();

    void on_zoomOut_clicked();

    void on_rotateRight_clicked();

    void on_rotateLeft_clicked();

    void on_miniRotateRight_clicked();

    void on_miniRotateLeft_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsItem *item;
    Image *image;
    PhotoType photo_35m_x_45mm;
    PhotoType photo_45m_x_45mm;
};

#endif // MAINWINDOW_H
