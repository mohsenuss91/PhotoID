#ifndef PAPER_H
#define PAPER_H

#include <QObject>
#include "photoType.h"
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QPixmap>
#include <QMessageBox>

class Paper : public QObject
{
    Q_OBJECT
public:
    explicit Paper(QPixmap *image, QObject *parent = 0);
    ~Paper();
    void print(int numOfCopies, PhotoType photoType, QWidget *widget);

protected:
    void createPaper();
    
signals:
    
public slots:

private:
    QPrinter *printer;
    QPixmap *image;
    
};

#endif // PAPER_H
