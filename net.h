#ifndef NET_H
#define NET_H

#include <iostream>

#include "input.h"
#include "layer.h"

using namespace std;

class net
{
public:
    //constructor
    inline net(vector<int> & numcells) {
        //input
        x.setsync(true);
        x.setnumcell(numcells[0]);
        //first line
        layers.push_back(layer(numcells[1]));
        layers[0].setcoord(0);
        layers[0].setweights(numcells[0]);
        //next lines
        for(unsigned int i=2; i<numcells.size(); i++){
            layers.push_back(layer(numcells[i]));
            layers[i-1].setcoord(i);
            layers[i-1].setweights(numcells[i-1]);
        }
    }

    //functional methods
    inline void spike() {
        //input
        x.update();
        //layers
        for(unsigned int i=layers.size()-1; i>0; i--)
            layers[i].spike(layers[i-1].getoutput());
        layers[0].spike(x.getoutput());
    }
    inline void print(vector< vector<float> > p) {
        system("clear");
        cout << "time = " << time << endl;
        for(unsigned int i=0; i<p.size(); i++){
            for(unsigned int j=0; j<p[i].size(); j++){
                cout << p[i][j] << " ";
            }
            cout << endl;
        }
    }

    //get methods
    inline void get(){
        getthreshold();
        getpotential();
        getoutput();
    }
    inline void getthreshold(){
        t.clear();
        t.push_back(x.getoutput());
        for(unsigned int i=0; i<layers.size(); i++)
            t.push_back(layers[i].getthreshold());
    }
    inline void getpotential(){
        q.clear();
        q.push_back(x.getoutput());
        for(unsigned int i=0; i<layers.size(); i++)
            q.push_back(layers[i].getpotential());
    }
    inline void getoutput(){
        y.clear();
        y.push_back(x.getoutput());
        for(unsigned int i=0; i<layers.size(); i++)
            y.push_back(layers[i].getoutput());
    }

    //run method
    inline void run() {
        time = 1;
        while(true){
            //spike
            x.update();
            spike();
            //print
            get();
            print(y);
            //wait
            sleep(1); time++;
        }
        exit(0);
    }

private:
    input x;
    vector<layer> layers;
    vector< vector<float> > t;
    vector< vector<float> > q;
    vector< vector<float> > y;

    int time;
};

#endif // NET_H
