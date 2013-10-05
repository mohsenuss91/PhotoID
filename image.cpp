#include "image.h"

Image::Image(QObject *parent) :
  QObject(parent)
{

}

Image::Image(QString realPath,QObject *parent) {

}

void Image::setRealPath(QString path) {
  this->realPath = path;
}

QString Image::getRealPath() const {
  return this->realPath;
}

void Image::setTempPath(QString path) {
  this->tempPath = path;
}

QString Image::getTempPath() const {
  return this->tempPath;
}

/*  =========================================================================
 *      - Description : this function change the color of image to gray.
 *      - Auther : Hachem Zerdia
 *      - Return : void
 *  =========================================================================
 */

void Image::black_white() {
    QFile file(this->tempPath);
    if(file.exists()) {
        QImage *image = new QImage(this->tempPath);
        QRgb col;
        int gray;
        int width = image->width();
        int height = image->height();
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                col = image->pixel(i, j);
                gray = qGray(col);
                image->setPixel(i, j, qRgb(gray, gray, gray));
            }
        }
        image->save(this->tempPath);
        delete image;
        emit wb_finished();
    }
}
