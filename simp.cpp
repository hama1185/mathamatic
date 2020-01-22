#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.141592

double func(double x){
    return (-0.1*cos(x)-0.087)*cos(x);
}

int main(){
    int n;
    double x;
    double s,s1,s2,h;
    double a,b;
    printf("Input n value\n");
    scanf("%d",&n);
    b = PI;
    a = 0;
    h = (b-a)/(2*n);
    s1 = 0;
    for(int i = 1;i <= 2*n-1; i+=2){
        x = a + h * i;
        s1 += 4 * func(x);
    }
    s2 = 0;
    for(int i = 2;i <= 2*n-2;i+=2){
        x = a + h * i;
        s2 += 2 * func(x);
    }
    s = (s1 + s2 + func(a) + func(b)) * h / 3;
    printf("s: %f\n", s);
    s = -s * (4/PI);
    printf("ans: %f\n", s);
}