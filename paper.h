#ifndef PAPER_H
#define PAPER_H

#include <QObject>
#include "photoType.h"

class Paper : public QObject
{
    Q_OBJECT
public:
    explicit Paper(QImage *image,QObject *parent = 0);
    void print(int numOfCopies, PhotoType photoType, QWidget *widget);

protected:
    void createPaper();
    
signals:
    
public slots:
    
};

#endif // PAPER_H
