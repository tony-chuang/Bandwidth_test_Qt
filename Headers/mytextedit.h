#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QTextEdit>
#include "myplot.h"
//#include "myprocess.h"

class QProcess;

class MyTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit MyTextEdit(QWidget *parent = 0);
    void StartCmd (MyPlot*&plot, QString text);
    void AppendConText(MyPlot*&plot);

signals:

public slots:
    void iperfStart();

private:
    QProcess *MyProc;
    QByteArray byteArray;
    MyPlot *textplot;
    char* c;
    char sec[4];
    char GBytes[7];
    char GBytes_sec[11];
    char testvalue[20];
    char* tests;
    char* testK;
    char* testKs;
    int lenK;
    int lenKs;
    int xnum;
    double ynum;
    int flag;
};

#endif // MYTEXTEDIT_H
