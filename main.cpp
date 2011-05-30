#include <QtGui/QApplication>

#include "mainwindow.h"
#include "net.h"

int main(int argc, char *argv[])
{
    //structure
    vector<int> numcells;
    numcells.push_back(10);
    numcells.push_back(10);
    numcells.push_back(10);
    numcells.push_back(10);
    numcells.push_back(10);
    numcells.push_back(10);
    numcells.push_back(10);
    numcells.push_back(10);
    numcells.push_back(10);

    //application
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(true);

    //iterface
//    MainWindow * w = new MainWindow();
//    w->setnumcells(numcells);
//    w->show();

    //network
    net n(numcells);
//    n.setmainwindow(w);
    n.run();

    //connection
//    for(unsigned int i=0; i<numcells.size(); i++)
//        for(int j=0; j<numcells[i]; j++)
//            w->setcolor(i,j,n.getcolor()[i][j]);

//    return a.exec();
    return 0;
}
