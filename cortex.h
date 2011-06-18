#ifndef CORTEX_H
#define CORTEX_H

#include <iostream>
#include "neuron.h"

using namespace std;

class cortex
{
public:
    //constructor
    inline cortex(int numcell){
        time = 0;

        for(int i=0; i<numcell; i++){
            neurons.push_back(neuron(numcell));
            neurons[i].setcoord(i);
            neurons[i].setweights(numcell);
            x.push_back(0);
        }
    }

    //set methods
    inline void clearx(){
        x.clear();
        for(unsigned int i=0; i<neurons.size(); i++)
            x.push_back(0);
    }
    inline void setinput(){
        for(unsigned int i=0; i<neurons.size(); i++)
            neurons[i].setinput(x);
    }

    //functional methods
    inline void spike(){
        for(unsigned int i=0; i<neurons.size(); i++)
            neurons[i].spike();
    }
    inline void learn(){
        for(unsigned int i=0; i<neurons.size(); i++)
            neurons[i].learn();
    }
    inline void addnoise(){
        float ampnoise = 0.0001;
        for(unsigned int i=0; i<x.size(); i++)
            x[i] += ampnoise*rand()/(float)RAND_MAX;
    }

    //get methods
    inline void getoutput(){
        x.clear();
        for(unsigned int i=0; i<neurons.size(); i++)
            x.push_back(neurons[i].getoutput());
    }
    inline int getmaxperiod(){
        int p = 0;
        for(unsigned int i=0; i<neurons.size(); i++){
            if(p<neurons[i].getperiod())
                p = neurons[i].getperiod();
        }
        return p;
    }
    inline void getperiod(){
        period.clear();
        period.resize(getmaxperiod()+1);
        for(unsigned int i=0; i<neurons.size(); i++){
            period[neurons[i].getperiod()]++;
        }
    }

    //print methods
    inline void printx(){
        cout << "time " << time << " x\t";
        for(unsigned int i=0; i<x.size(); i++){
            cout << x[i] << "\t";
        }
        cout << endl;
        cout.flush();
    }
    inline void printpotential(){
        cout << "time " << time << " q\t";
        for(unsigned int i=0; i<neurons.size(); i++){
            cout << neurons[i].getpotential() << "\t";
        }
        cout << endl;
        cout.flush();
    }
    inline void printover(){
        cout << "time " << time << " q-ø\t";
        for(unsigned int i=0; i<neurons.size(); i++){
            cout << neurons[i].getpotential() - neurons[i].getthreshold() << "\t";
        }
        cout << endl;
        cout.flush();
    }
    inline void printthreshold(){
        cout << "time " << time << " ø\t";
        for(unsigned int i=0; i<neurons.size(); i++){
            cout << neurons[i].getthreshold() << "\t";
        }
        cout << endl;
        cout.flush();
    }
    inline void printoutput(){
        cout << "time " << time << " y\t";
        for(unsigned int i=0; i<neurons.size(); i++){
            cout << neurons[i].getoutput() << "\t";
        }
        cout << endl;
        cout.flush();
    }
    inline void printtime(){
        cout << "time " << time << " t\t";
        for(unsigned int i=0; i<neurons.size(); i++){
            cout << neurons[i].gettime() << "\t";
        }
        cout << endl;
        cout.flush();
    }
    inline void printperiod(){
        cout << "time " << time << " p\t";
        for(unsigned int i=0; i<neurons.size(); i++){
            cout << neurons[i].getperiod() << "\t";
        }
        cout << endl;
        cout.flush();
    }
    inline void printmperiod(){
        cout << "time " << time << " mp\t";
        for(unsigned int i=0; i<neurons.size(); i++){
            cout << neurons[i].getmperiod()/(float)time << "\t";
        }
        cout << endl;
        cout.flush();
    }

    //run
    inline void run(){
        time++;

        //x to neuron
        setinput();

        //neuron spikes
        spike();

        //print
        printx();
        printpotential();
        printthreshold();
        printover();
        printoutput();

        //neuron to x
        getperiod();
        getoutput();

        //x noise
        addnoise();

        //neuron learn
        learn();

        //sleep
        usleep(2e6);

        //refresh
        int todo = 2;
        switch(todo){
        case 1:
            cout << endl;
            break;
        case 2:
            system("clear");
            break;
        }
    }

private:
    //attributs
    vector<neuron> neurons;
    vector<float> x;
    vector<int> period;

    int time;
};

#endif // CORTEX_H
