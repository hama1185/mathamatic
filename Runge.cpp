#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.141592

double func(double x, double y){
    return (3*y/(1+x));
}

int main(){
    int n;
    double x,y,y0;
    double k1,k2,k3,k4,h,n;
    double a,b;
    
    a = 0;
    b = 1;
    y0 = 1;
    n = 64;
    h = (b-a)/n;
    x = a;
    y = y0;
    while(x < b){
        k1 = func(x ,y); 
        k2 = func(x + h / 2.0 ,y + k1*h / 2.0);
        k3 = func(x + h / 2.0 ,y + k2*h / 2.0);
        k4 = func(x + h,y + k3 * h);

        y = y + h * (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6;
        x += h;
    }
    
    printf("ans: %f\n", y);
}