#include "myplot.h"
#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_series_data.h>

#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_marker.h>
#include <qwt_legend.h>
#include <qwt_symbol.h>

MyPlot::MyPlot(QWidget *parent) :
    QwtPlot(parent)
{
}

void MyPlot::PaintPlotFirst(int xnum, double ynum){
    this->detachItems();
    this->replot();
    curve = new QwtPlotCurve("Curve");
    QwtSymbol *symbol = new QwtSymbol(QwtSymbol::Ellipse, QBrush(Qt::red), QPen(Qt::red, 2), QSize(4, 4));
    xs.clear();
    ys.clear();
    xs.append(xnum);
    ys.append(ynum);
    data = new QwtPointArrayData(xs, ys);
    curve->setData(data);
    curve->setStyle(QwtPlotCurve::Lines);
    curve->setCurveAttribute(QwtPlotCurve::Fitted, true);
    curve->setPen(QPen(Qt::blue));
    curve->setSymbol(symbol);
    curve->attach(this);
    this->replot();
}

void MyPlot::PaintPlot(int xnum, double ynum){
    this->detachItems();
    this->replot();
    curve = new QwtPlotCurve("Curve");
    QwtSymbol *symbol = new QwtSymbol(QwtSymbol::Ellipse, QBrush(Qt::red), QPen(Qt::red, 2), QSize(4, 4));
    xs.append(xnum);
    ys.append(ynum);
    data = new QwtPointArrayData(xs, ys);
    curve->setData(data);
    curve->setStyle(QwtPlotCurve::Lines);
    curve->setCurveAttribute(QwtPlotCurve::Fitted, true);
    curve->setPen(QPen(Qt::blue));
    curve->setSymbol(symbol);
    curve->attach(this);
    this->replot();
}

