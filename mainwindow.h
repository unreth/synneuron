#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <KDE/KLed>
#include <ui_mainwindow.h>

using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setnumcells(vector<int> & numcells);
    void setcolor(int i, int j, QColor & c);

private:
    Ui::MainWindow *ui;

    QWidget * net_widget;
    QHBoxLayout * net_layout;
    vector<QWidget *> layer_widgets;
    vector<QVBoxLayout *> layer_layouts;
    vector< vector<KLed *> > neuron_widgets;
};

#endif // MAINWINDOW_H
