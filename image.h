#ifndef IMAGE_H
#define IMAGE_H

#include <QObject>
#include <QString>
#include <QImage>
#include <QFile>
#include <QGraphicsScene>
#include "photoType.h"

class Image : public QObject
{
  Q_OBJECT
public:
  explicit Image (QObject *parent = 0);
  Image(QString realPath,QObject *parent = 0);
  void setRealPath(QString path);
  QString getRealPath() const;
  void setTempPath(QString path);
  QString getTempPath() const;
  QImage crop(QGraphicsScene *scene, PhotoType const &photoType); // crop the image and save it in temp path.

signals:
  void wb_finished(); // emited when black_white() finiched.
  
public slots:
  void black_white();

private:
  QString realPath;
  QString tempPath;
  
};

#endif // IMAGE_H
