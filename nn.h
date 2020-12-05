#ifndef _TEST1_H_
#define _TEST1_H_

class NN{
public:
    double Neuron(double* x,double* w,unsigned int x_len,unsigned int w_len,double bias,const char* name);
private:
    double Sigma(double* x,double* w,unsigned int x_len,unsigned int w_len);
    double ReLU(double s);
};

double NN::Sigma(double* x,double* w,unsigned int x_len,unsigned int w_len){
    double y = 0.0;
    for (unsigned int i = 0; i < x_len; i++) {
        y += x[i]*w[i]; 
    }
    return (double)y;
}

double NN::ReLU(double s){
    if(s>0.0){
        return (double)s;
    }
    else{
        return 0.0;
    }
}

double NN::Neuron(
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

#endif // _TEST1_H_