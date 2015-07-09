#ifndef MYPLOT_H
#define MYPLOT_H

#include <qwt_plot.h>
#include <qwt_series_data.h>

class QwtPlotCurve;
class QwtPointSeriesData;

class MyPlot : public QwtPlot
{
    Q_OBJECT
public:
    explicit MyPlot(QWidget *parent = 0);
    QwtPlotCurve *curve;
    int xnum;
    double ynum;
    void PaintPlot(int, double);
    void PaintPlotFirst(int, double);
    QVector<double> xs;
    QVector<double> ys;
    QwtPointArrayData * data;

signals:

public slots:

};

#endif // MYPLOT_H
