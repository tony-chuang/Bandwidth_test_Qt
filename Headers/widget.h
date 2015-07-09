#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui/QWidget>
#include "mytextedit.h"
#include "myplot.h"

#include "ui_form.h"

class QTextEdit;
class QPushButton;
class QLineEdit;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
    QPushButton *button;
    MyTextEdit *txt;
    MyPlot *plot;
    QLineEdit *input;

protected:

signals:

public slots:
    void iperfstart();
};

#endif // WIDGET_H
