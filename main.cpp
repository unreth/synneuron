#include "cortex.h"

#include <iostream>
#include <iomanip>
#include <math.h>
int main()
{
    //network
    cortex c(6);

    //cout settings
    cout << setiosflags(ios::fixed) << setprecision(3);

    //run
    c.clearx();
    while(true){ c.run(); }

    return 0;
}
