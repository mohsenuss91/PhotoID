#include "paper.h"

Paper::Paper(QPixmap *image, QObject *parent) :
    QObject(parent)
{
    this->image = image;
    printer = new QPrinter(QPrinter::PrinterResolution);
}

void Paper::createPaper() {
    printer->setPageSize(QPrinter::A6);
    printer->setResolution(250);
    printer->setOutputFormat(QPrinter::PdfFormat);
    //printer->setOutputFormat(QPrinter::NativeFormat);
    printer->setOutputFileName("test.pdf");
    printer->setOrientation(QPrinter::Landscape);
    printer->setPageMargins(0,0,0,0,QPrinter::Millimeter);
}

void Paper::print(int numOfCopies, PhotoType photoType, QWidget *widget) {
    this->printer->setNumCopies(numOfCopies);
    QPainter *painter = new QPainter();
    if(painter->begin(this->printer)) {

        int x = 20;
        int y = 100;

        for(int i = 0; i < 8;i++) {

            if(i < 4) {
                painter->drawPixmap(x,y,photoType.Width,photoType.Height,*image);
                x += (photoType.Width + 20);
            } else {
                y = (photoType.Height + 160);
                x -= (photoType.Width + 20);
                painter->drawPixmap(x,y,photoType.Width,photoType.Height,*image);
            }
        }

        painter->end();
    } else {

        QMessageBox::warning(widget,"Warning","There is no printer installed");
    }

}

Paper::~Paper() {
    delete printer;
}
