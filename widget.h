#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QLineEdit>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void startDrawing();
private:
    QVBoxLayout     *lay;
    QLabel          *basePathLab;
    QLineEdit       *basePath;
    QLabel          *pixelImagePathLab;
    QLineEdit       *pixelImagePath;
    QLabel          *savePathLab;
    QLineEdit       *savePath;
    QLabel          *status;
    QPushButton     *redraw;
};

#endif // WIDGET_H
