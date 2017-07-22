  #include "imagechanger.h"
#include <QPainter>
#include <QRgb>
#include <QColor>
#include <QDebug>

ImageChanger::ImageChanger(QString parented, QString pixelImage)
{
    pixelColor = qRgb(0,255,0);
    basePicture = QImage(parented);
    pixelImg = QPixmap(pixelImage).toImage();
//    pixelImg = QImage(pixelImage);
}

QPixmap ImageChanger::getImage()
{
    int tempW = pixelImg.width();
    int tempH = pixelImg.height();
    QPixmap temp = QPixmap(pixelImg.width()*basePicture.width(), pixelImg.height()*basePicture.height());
    QPainter painter(&temp);
    for(int x = 0; x < basePicture.width(); x++)
    {
        for(int y = 0; y < basePicture.height(); y++)
        {
            if ((y%2==0) && (x%2==0))
            {
                painter.drawImage((tempW*x)-1, (tempH*y)-1, getPixel(basePicture.pixel(x,y)));
            }
            else
            {
                painter.fillRect(QRectF(QPoint(x*tempW-1,y*tempH-1), QSize(tempW, tempH)), QBrush(QColor(basePicture.pixel(x,y)), Qt::SolidPattern));
            }
        }
        qDebug() << x;
    }
    return temp;
}

QImage ImageChanger::getPixel(uint color)
{
    QImage secondImg(pixelImg);
    for(int x = 0; x < secondImg.width(); x++)
    {
        for(int y = 0; y < secondImg.height(); y++)
        {
            if(secondImg.pixel(x,y)==pixelColor)
            {
                secondImg.setPixel(x,y, color);
            }
        }
    }
    return secondImg;
}
