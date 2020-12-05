#include <stdio.h>
#include <stdlib.h>

double Sigma(double*,double*,unsigned int,unsigned int);
double ReLU(double);
double Neuron(double*,double*,unsigned int,unsigned int,double,const char*);

int main(void){
    double x[] = {0.5,0.4,0.3,0.2,0.1}; 
    double w[] = {0.1,0.2,0.3,0.4,0.5};
    double bias= 0.05;

    unsigned int xLength = sizeof(x)/sizeof(double);
    unsigned int wLength = sizeof(w)/sizeof(double);

    double y = Neuron(x,w,xLength,wLength,bias,"ReLU");
    // printf("%f",y);

    return (int)0;
}

double Sigma(double* x,double* w,unsigned int x_len,unsigned int w_len)
{
    double y = 0.0;
    for (unsigned int i = 0; i < x_len; i++) {
        y += x[i]*w[i]; 
    }
    return (double)y;
}

double ReLU(double s)
{
    if(s>0.0){
        return (double)s;
    }
    else{
        return 0.0;
    }
}

double Neuron(
    double* x,
    double* w,
    unsigned int x_len,
    unsigned int w_len,
    double bias,
    const char* name){

    double y = 0.0;

    // 数列の和
    double s = Sigma(x,w,x_len,w_len) + bias;

    // 活性化関数
    if (name == (const char*)"ReLU"){
        y = ReLU(s);
    }

    return (double)y;
}