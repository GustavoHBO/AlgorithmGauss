#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


void main(){
    int valueX = 7, valueY = 7;
    float valor[7][7]={
                                 {45,3,-14,1,-7,8,12},
                                 {-3,2,-36,5,7,-1,-2},
                                 {4,4,13,-1,1,-2,0},
                                 {5,-5,-6,18,2,1,-3},
                                 {-11,1,-4,23,-5,11,23},
                                 {-25,16,-11,9,9,-15,-12},
                                 {0,0,0,0,0,0,0}};

    clearTerms(7, valor, 7);
    float array[7 - 1];
    systemResolution(7, valor, 7, array);
    int i = 0, j = 0;
    for(i = 0; i < 7; i++){
        for (int j = 0; j < 7; j++)
            printf("%.2f\t", valor[i][j]);
        printf("\n");
    }
    printf("(");
    for(i = 0; i < valueX-1; i++){
        printf("%.2f", array[i]);
        if(i < valueX-2){
            printf(",");
        }
    }
    printf(")\n");
    return;
}
