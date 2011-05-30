#ifndef LAYER_H
#define LAYER_H

#include <QColor>

#include "neuron.h"

using namespace std;

class layer
{
public:
    //constructor
    inline layer(int & numcell){
        neurons.resize(numcell);
        for(unsigned int j=0; j<neurons.size(); j++){
            y.push_back(neurons[j].getoutput());
        }
    }

    //operators
    inline layer & operator= (const layer & im){
        neurons = im.neurons;
        x = im.x;
        q = im.q;
        y = im.y;
        return (*this);
    }

    //set methods
    inline void setcoord(int i){
        this->i = i;
        for(unsigned int j=0; j<neurons.size(); j++)
            neurons[j].setcoord(i, j);
    }
    //functional methods
    inline void setweights(int numcells){
        for(unsigned int i=0; i<neurons.size(); i++)
            neurons[i].setweights(numcells);
    }
    inline vector<float> spike(vector<float> x){
        this->x = x;
        y.clear();
        for(unsigned int j=0; j<neurons.size(); j++){
            this->neurons[j].setinput(x);
            y.push_back(neurons[j].spike());
        }
        return y;
    }

    //get methods
    inline vector<float> getthreshold(){
        t.clear();
        for(unsigned int j=0; j<neurons.size(); j++)
            t.push_back(neurons[j].getthreshold());
        return t;
    }
    inline vector<float> getpotential(){
        q.clear();
        for(unsigned int j=0; j<neurons.size(); j++)
            q.push_back(neurons[j].getpotential());
        return q;
    }
    inline vector<float> getoutput(){
        y.clear();
        for(unsigned int j=0; j<neurons.size(); j++)
            y.push_back(neurons[j].getoutput());
        return y;
    }

private:
    //attributes
    int i;

    vector<neuron> neurons;
    vector<float> x;
    vector<float> t;
    vector<float> q;
    vector<float> y;
};

#endif // LAYER_H
