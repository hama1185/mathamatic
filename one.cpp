#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double func(double x);

int main(void){
    double fa,fb;
    double A = 1.4;
    double B = 1.5;
    double C,fc;
    int count = 0;
    do{
        count++;
        fa = func(A);
        fb = func(B);
        C = (A*fb - B*fa)/(fb - fa);
        fc = func(C);
        if(fc*fb < 0){
            A=C;
        }
        else{
            B = C;
        }
    }while(fabs(fc) > 0.0001);
    
    printf("ans:%f\n",C);
    printf("count:%d\n",count);
    return 0;
}

double func(double x){
    return exp(x)-3*x;
}