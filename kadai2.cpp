#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Q1
#define N 4

int main(){
    double pivot;
    double array[N][N+1] = {{2,8,2,-3,2},{4,6,-2,-1,1},{2,-4,-2,-1,3},{1,-5,2,1,-2}};
    for(int i = 0; i < N; i++){
        pivot = array[i][i];
        for(int j = i; j < N + 1; j++){
            array[i][j] = array[i][j] / pivot;
        }
        for(int k = 0; k < N; k++){
            if((k - i) != 0){
                double aik = array[k][i];
                for(int j = i;j < N + 1; j++){
                    array[k][j] = array[k][j] - aik * array[i][j];
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        printf("ans:%f\n",array[i][N]);
    }
    return 0;
}