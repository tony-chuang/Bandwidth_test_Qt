#include <QProcess>
#include "mytextedit.h"
#include "myplot.h"
#include "widget.h"

MyTextEdit::MyTextEdit(QWidget *parent) :
    QTextEdit(parent)
{
    this->setEnabled(false);
}

void MyTextEdit::StartCmd(MyPlot *&plot, QString text){
    textplot = plot;
    QByteArray byteArray=text.toLocal8Bit ();
    char *c=byteArray.data();
    char cmd[50]="iperf -c ";
    char cmd2[]= " -i 1 -f G";
    strcat(cmd, c);
    strcat(cmd, cmd2);

    MyProc = new QProcess;
    connect (MyProc, SIGNAL(readyRead()), this, SLOT(iperfStart()));
    MyProc->start(cmd);
    this->moveCursor(QTextCursor::End);
    //this->append(cmd);
    xnum = 0;
    ynum = 0;
    flag = 0;
}

void MyTextEdit::iperfStart() {
    this->AppendConText(textplot);
}

void MyTextEdit::AppendConText(MyPlot*&plot){
    memset(sec, '\0', 4);
    sprintf(sec, "%s", "sec");
    memset(GBytes, '\0', 7);
    sprintf(GBytes, "%s", "GBytes");
    memset(GBytes_sec, '\0', 11);
    sprintf(GBytes_sec, "%s", "GBytes/sec");
    memset(testvalue, '\0', 20);
    lenK = 0;
    lenKs = 0;

    byteArray = MyProc->readAll();
    c = byteArray.data();
    tests = strstr(c, sec);
    testK = strstr(c, GBytes);
    testKs = strstr(c, GBytes_sec);
    if(tests != NULL && testK != NULL && testKs != NULL){
        lenK = strlen(testK);
        lenKs = strlen(testKs);
        strncpy(testvalue, testK+8, lenK-lenKs-9);
        xnum++;
        ynum = atof (testvalue);
        if(flag == 0){
            plot->PaintPlotFirst(xnum, ynum);
            flag = 1;
        }else{
            plot->PaintPlot(xnum,ynum);
        }
        this->moveCursor(QTextCursor::End);
        this->insertPlainText(c);
    }
}
