#include <stdio.h>
#include <stdlib.h>
#include "nn.h"

int main(void){
    NN nn;

    double x[] = {0.5,0.4,0.3,0.2,0.1}; 
    double w[] = {0.1,0.2,0.3,0.4,0.5};
    double bias= 0.05;

    unsigned int xLength = sizeof(x)/sizeof(double);
    unsigned int wLength = sizeof(w)/sizeof(double);

    double y = nn.Neuron(x,w,xLength,wLength,bias,"ReLU");
    printf("%f\n",y);

    return (int)0;
}
