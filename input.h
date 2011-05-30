#ifndef INPUT_H
#define INPUT_H

#include <stdlib.h>
#include <vector>
#include <cmath>

using namespace std;

class input
{
public:
    inline input() { time = 0; }

    inline void setsync(bool sync){
        this->sync = sync;
    }
    inline void update(){
        time++;
        float rnd;
        if(!sync || time*frequency>1){
            for(unsigned int i=0; i<y.size(); i++){
                rnd = rand()/(float)RAND_MAX;
                y[i] = round(intensity + rnd - 0.5);
            }
            time += -1/frequency;
        }
    }
    inline void setnumcell(int numcell) {
        y.resize(numcell);
    }

    inline vector<float> & getoutput(){
        return y;
    }

private:
    vector<float> y;
    float time;
    static const float frequency = 1; // frequency > 0
    static const float intensity = 0.7; // intensity [0,+1]
    bool sync;
};

#endif // INPUT_H
