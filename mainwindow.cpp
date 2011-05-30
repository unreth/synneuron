#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setcolor(int i, int j, QColor & c) {
    neuron_widgets[i][j]->setColor(c);
}

void MainWindow::setnumcells(vector<int> & numcells) {
    //interface
    net_widget = new QWidget();
    net_layout = new QHBoxLayout();
    layer_widgets.resize(numcells.size());
    layer_layouts.resize(numcells.size());
    neuron_widgets.resize(numcells.size());

    for(unsigned int i=0; i<numcells.size(); i++){
        neuron_widgets[i].resize(numcells[i]);

        layer_layouts[i] = new QVBoxLayout();
        for(int j=0; j<numcells[i]; j++){
            neuron_widgets[i][j] = new KLed();
            layer_layouts[i]->addWidget(neuron_widgets[i][j]);
        }
        layer_widgets[i] = new QWidget();
        layer_widgets[i]->setLayout(layer_layouts[i]);
        net_layout->addWidget(layer_widgets[i]);
    }
    net_widget->setLayout(net_layout);
    setCentralWidget(net_widget);
}
