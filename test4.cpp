#include <stdio.h>
#include <math.h>

#define N 3               // 連立方程式の大きさ
#define EPS 1e-15         // 計算誤差の許容値


int main(void){
   double a[N+1][N+1], x[N+1], b[N+1];
   FILE *fp;
   fp = fopen("text.txt","w");
   double dx, absx, sum, after;
   int i,j;
   int count = 0;
   a[1][1]=3.0;  a[1][2]=1.0;  a[1][3]=1.0;  // 係数行列
   a[2][1]=1.0;  a[2][2]=5.0;  a[2][3]=2.0;
   a[3][1]=1.0;  a[3][2]=2.0;  a[3][3]=5.0;

   b[1]=10.0;                         // 同次項
   b[2]=21.0;
   b[3]=30.0;
 
   x[1]=0.0;                          // 近似解の初期値
   x[2]=0.0;
   x[3]=0.0;
    
    do{                                // 反復計算のループ
        dx=0.0;
        absx=0.0;
        for(i=1;i<=N;i++){
            sum=0;
            for(j=1;j<=N;j++){
   	            if(i != j){
   	                sum +=  a[i][j]*x[j];
   	            }
            }
            after=1.0/a[i][i]*(b[i]-sum);   // 反復計算後の近似解
            dx+=fabs(after-x[i]);           // 近似解の変化量を加算
            absx+=fabs(after);              // 近似解の総和計算
            x[i]=after;                     // 新しい近似解を代入
        }
        count++;
        fprintf(fp,"%d",count);
        fprintf(fp,"\n");
        printf("count:%d\n",count);
        for(i=1;i<=N;i++){
            fprintf(fp,"%.20f",x[i]);
            fprintf(fp,"\n");
            printf("x[%d]=%25.20f\n",i,x[i]);
        }
        fprintf(fp,"\n");
    }while(dx/absx > EPS);            // 計算終了条件
    fclose(fp);
    return 0;
}