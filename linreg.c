#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float data[][2]={
            {1.0,2.0},
            {2.0,4.0},
            {3.0,6.0},
            {4.0,8.0},
            {5.0,10.0},};
#define N (sizeof(data)/sizeof(data[0]))
//Hypothesis Function 
float hypothesis(float x,float W){
    return W*x;
}
//Cost Function
float cost(float x, float y, float W){
    return y - hypothesis(x, W);
};
//Optimization Function
float gradient(float W){
    float dJ=0.0;
    for(int i=0;i<N;i++){
        float x=data[i][0];
        float y=data[i][1];
        float E=cost(x, y, W);
        dJ+=E*x;
    }
    return dJ;
}
float train(int epochs,float lr,float W){
    for(int i=0;i<epochs;i++){        
        W=W+lr*gradient(W);
        float total_error=0.0;
        for (int i = 0; i < N; i++)
        {
            float x=data[i][0];
            float y=data[i][1];
            total_error += fabs((hypothesis(x, W) - y) / y) * 100;
        }
        float percentage_E=total_error/N;
        
        if(i%10==0){
            printf("Epoch: %d| Weight: %.1f| Percentage Error: %.1f\n",i,W,percentage_E);
        }
    };
    return W;
}
float test(float W){
    for(int i=0;i<N;i++){
        float x=data[i][0];
        float y=data[i][1];
        printf("Predicted Value: %.1f, Actual Value: %.1f\n",hypothesis(x,W),y);
    }
}
int main(){
    int epochs=400;
    float lr=0.001;
    srand(time(NULL));
    float W=rand();
    W=train(epochs,lr,W);
    test(W);
    return 0;
}