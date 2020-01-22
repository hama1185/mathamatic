#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.141592

double func(double x){
    return (-0.1*cos(x)-0.087)*cos(x);
}

int main(){
    int n,k;
    double x;
    double s,h;
    double a,b;
    printf("Input k value\n");
    scanf("%d",&k);
    n = pow(2, k);
    b = PI;
    a = 0;
    h = (b-a)/n;
    s = 0;
    for(int i = 0;i < n;i++){
        x = a + h * i;
        s += 2 * func(x);
    }
    s = 0.5 * (s + func(a) + func(b)) * h;
    printf("s: %f\n", s);
    s = -s * (4/PI);
    printf("ans: %f\n", s);
}