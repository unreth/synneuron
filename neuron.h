#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <stdlib.h>

using namespace std;

class neuron
{
public:
    //constructor
    inline neuron(int numcell) {
        stepup = 1.01;
        stepdown = 0.95;

        t = 100*numcell*rand()/(float)RAND_MAX;
        y = 0;

//        q = 0;
//        deltat = 0;

        time = 0;
        period = 0;
        mperiod = 0;
    }

    //set methods
    inline void setcoord(int coord) {
        this->coord = coord;
    }
    inline void setweights(int numcells){
        w.clear();
        for(int i=0; i<numcells; i++)
            w.push_back(rand()/(float)RAND_MAX);
    }
    inline void setinput(vector<float> x){
        this->x.clear();
        for(unsigned int i=0; i<x.size(); i++){
            this->x.push_back(x[i]);
        }
    }
    inline void setoutput(float y){
        this->y = y;
    }

    //functional methods
    inline float spike(){
        time++;
        q = 0;

        //integration
        for(unsigned int k=0; k<x.size(); k++){
            q += x[k]*w[k];
        }

        //spike?
        if(q>t){
            //spike
            y = 1;
            deltat = stepup*(q-t); //stepup
            period = time;
            mperiod += period*period;
            time = 0;
        } else {
            //not spike
            y = 0;
            deltat = -stepdown*t;
        }

        return y;
    }
    inline void learn(){
        t += deltat;
    }

    inline void addnoise(float noise){
        y += noise;
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
    inline int gettime(){
        return time;
    }

    inline int getperiod(){
        return period;
    }
    inline int getmperiod() {
        return mperiod;
    }

private:
    //attributes
    int coord;
    float stepup;
    float stepdown;

    vector<float> w;    //weight
    float t;            //threshold
    float deltat;       //threshold variation

    vector<float> x;    //input
    float q;            //potential
    float y;            //output

    int time;           //time
    int period;         //period
    int mperiod;        //mean period * time
};

#endif // NEURON_H
