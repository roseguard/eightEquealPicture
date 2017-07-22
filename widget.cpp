#include "widget.h"
#include "imagechanger.h"
#include <QFile>
#include <QDebug>

#include <QImage>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    lay = new QVBoxLayout(this);

    basePathLab = new QLabel(tr("Path to base image"), this);
    basePath = new QLineEdit("D:\\test.jpg", this);

    pixelImagePathLab = new QLabel(tr("Image which one would be a pixel"), this);
    pixelImagePath = new QLineEdit("D:\\test.bmp", this);

    savePathLab = new QLabel(tr("Path for final image"), this);
    savePath = new QLineEdit("D:\\end.png", this);\

    redraw = new QPushButton("start", this);

    connect(redraw, SIGNAL(clicked(bool)), this, SLOT(startDrawing()));

    lay->addWidget(basePathLab);
    lay->addWidget(basePath);
    lay->addWidget(pixelImagePathLab);
    lay->addWidget(pixelImagePath);
    lay->addWidget(savePathLab);
    lay->addWidget(savePath);
    lay->addWidget(redraw);
}

Widget::~Widget()
{

}

void Widget::startDrawing()
{
    redraw->setDisabled(true);
    redraw->setText("Solving");

    ImageChanger img(basePath->text(), pixelImagePath->text());
    img.getImage().save(savePath->text());

    redraw->setEnabled(true);
    redraw->setText("Solved");
}
