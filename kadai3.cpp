#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Q2

#define N 4

void solve(double array[][N+1]);

int main(){
    double array[N][N+1];
    double frame[4][2];

    printf("Input coordinate\n");
    for(int i = 0; i < 4;i++){
        printf("%d:\n", i + 1);
        printf("x,y\n");
        scanf("%lf", &frame[i][0]);
        scanf("%lf", &frame[i][1]);
    }

    //input y
    for(int i = 0;i < N;i++){
        array[i][4] = frame[i][1];
    }
    //input d's coefficient
    for(int i = 0;i < N;i++){
        array[i][3] = 1;
    }
    //input c's coefficient
    for(int i = 0;i < N;i++){
        array[i][2] = frame[i][0];
    }
    //input b's coefficient
    for(int i = 0;i < N;i++){
        array[i][1] = frame[i][0] * frame[i][0];
    }
    //input a's coefficient
    for(int i = 0;i < N;i++){
        array[i][0] = frame[i][0] * frame[i][0] * frame[i][0];
    }
    solve(array);

    for(int i = 0; i < N; i++){
        printf("ans:%.5f\n",array[i][N]);
    }

    return 0;
}

void solve(double array[][N+1]){
    double pivot;
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
}