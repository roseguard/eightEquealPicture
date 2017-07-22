#ifndef IMAGECHANGER_H
#define IMAGECHANGER_H

#include <QImage>
#include <QPixmap>

class ImageChanger
{
public:
    ImageChanger(QString parented, QString pixelImage);
    QPixmap getImage();

private:
    QImage getPixel(uint color);

private:
    QImage   basePicture;
    QImage   baseImage;
    QImage   pixelImg;
    QRgb     pixelColor;

};

#endif // IMAGECHANGER_H
