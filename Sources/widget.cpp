#include <QtGui/QWidget>
#include <QtGui/QSpinBox>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QString>
#include <QProcess>
#include <QLineEdit>

#include <stdio.h>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_series_data.h>

#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_legend.h>

#include "widget.h"
#include "myplot.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    txt = new MyTextEdit;
    button = new QPushButton("iperf");
    input = new QLineEdit;

    plot = new MyPlot();
    plot->setAxisTitle(QwtPlot::xBottom, "sec");
    plot->setAxisTitle(QwtPlot::yLeft, "GBytes/sec");
    plot->setAxisScale(QwtPlot::xBottom, 0.0, 12, 1);
    plot->setAxisScale(QwtPlot::yLeft, 3.0, 4.5);
    (void) new QwtPlotMagnifier(plot->canvas());
    (void) new QwtPlotPanner(plot->canvas());

    connect(button, SIGNAL(clicked()), this, SLOT(iperfstart()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(input);
    layout->addWidget(button);
    layout->addWidget(txt);
    layout->addWidget(plot);

    setLayout(layout);
    this->resize(1200,800);
}

void Widget::iperfstart() {
    QString text = input->text();
    txt->StartCmd(plot, text);
}

Widget::~Widget()
{

}
