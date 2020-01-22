#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double func(double x, double y){
    return 5; 
}

int main(){
    FILE *outFile;

    outFile = fopen("outputData.csv", "w");

    int a,b,eta;
    double x,y,h,n;
    a = 0;
    b = 2;
    eta = 2;

    for(int i = 0; i < 9;i++){
        fprintf(outFile, "\n");
        n = pow(2 , i);
        h = (b - a) / n;
        x = a;
        y = eta;
        while(x < b){
            y = y + h * func(x,y);
            x = x + h;
            fprintf(outFile, "%f,%f",x,y);
            fprintf(outFile, "\n");
        }
    }
    fclose(outFile);
    free(outFile);
}