#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x){
    return exp(x)-3*x;
}
double dfunc(double x){
    return exp(x)-3;
}

int main(){
    double eps = 0.001;
    
    double x0,x1,dx,fx0,dx0;
    int count = 0;
    
    for(int x = 3;x >=0; x--){
        do{
            x0 = x; 
            fx0 = func(x0);
            dx0 = dfunc(x0);
            x1 = x0 - fx0 / dx0;
            dx = fabs(x1 - x0);
            x0 = x1;
            count++;
        }while (dx > eps);
        printf("x:%d\n",x);
        printf("ans:%f\n",x0);
        printf("count:%d\n",count);
    }
    return 0;
}