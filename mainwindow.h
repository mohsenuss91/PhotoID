#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "image.h"
#include "photoType.h"

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
private:
    Ui::MainWindow *ui;
    Image *image;
    PhotoType photo_35m_x_45mm;
    PhotoType photo_45m_x_45mm;
};

#endif // MAINWINDOW_H
