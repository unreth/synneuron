#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <stdlib.h>
#include <QColor>

using namespace std;

class neuron
{
public:
    //constructor
    inline neuron() {
        t = 1;
        q = 0;
        y = 0;
    }

    //operators
    inline neuron & operator= (const neuron & im){
        i = im.i;
        j = im.j;
        w = im.w;
        x = im.x;
        t = im.t;
        q = im.q;
        y = im.y;
        return (*this);
    }

    //set methods
    inline void setcoord(int i, int j) {
        this->i = i;
        this->j = j;
    }
    inline void setweights(int numcells){
        w.clear();
        for(int i=0; i<numcells; i++)
            w.push_back(rand()/(float)RAND_MAX); //random [0,+1]
    }
    inline void setinput(vector<float> x){
        this->x = x;
    }

    //functional methods
    inline float spike(){
        q = 0;
        for(unsigned int k=0; k<x.size(); k++) q += x[k]*w[k];
        if(q>t){
            y = 1;
            t = 1.5*q;
        } else {
            y = 0;
            t += -0.2*t;
        }
        return y;
    }

    //get methods
    inline float getthreshold(){
        return t;
    }
    inline float getpotential(){
        return q;
    }
    inline float getoutput(){
        return y;
    }

private:
    //attributes
    int i, j;

    vector<float> w;    //weight
    vector<float> x;    //input
    float t;            //threshold
    float q;            //soma potential
    float y;            //output
};

#endif // NEURON_H
