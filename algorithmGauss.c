#include <stdlib.h>
#include <stdio.h>

/*
    param - matrixAugmented is a matrix of coefficient plus independent terms.
    param - valueX is horizantal size
    param - valueY is vertical size.
*/
float* methodGauss(float* matrixAugmented, int valueX, int valueY){


}

/*
 *   Change the lines in a matrix.
 */
void changePlaceLine(int valueY, float matrixAugmented[][valueY], int line1, int line2, int valueX){
    if(matrixAugmented == NULL || line1 < 0 || line2 < 0 || line1 == line2 || valueX <= 0 || line1 > valueY || line2 > valueY){
        return;
    }
    float value;
    int i = 0;
    for(i = 0; i < valueX; i++){
        value = matrixAugmented[line1][i];
        matrixAugmented[line1][i] = matrixAugmented[line2][i];
        matrixAugmented[line2][i] = value;
    }
}

void clearTerms(int valueY, float matrixAugmented[][valueY], int valueX){
    float valueMN = 0;
    int i = 0, j = 0, newLine = 0, k = 0;
    if(valueY == 0 || matrixAugmented == NULL){
        return;
    }
    for(i = 0; i < valueY - 1; i++){
        newLine = i;
        while(matrixAugmented[i][i] == 0){
            if(newLine + 1 == valueY){
                i++;
                break;
            }
            changePlaceLine(valueY, matrixAugmented, i, ++newLine, valueX);
        }
        for(k = 1; k + i < valueY; k++){
            valueMN = matrixAugmented[i+k][i] / matrixAugmented[i][i];
            for(j = 0; j < valueX; j++){
                matrixAugmented[i+k][j] -= valueMN * matrixAugmented[i][j];
            }
        }
    }
}

void changeLine(int valueY, float matrixAugmented[][valueY], float arrayLine[], int line, int valueX){
    float value;
    int i = 0;

    if(valueY < line || matrixAugmented == NULL || arrayLine == NULL){
        return;
    }
    for(i = 0; i < valueX; i++){
        matrixAugmented[line][i] = arrayLine[i];
    }
}

/*
 *   Change the column in a matrix.
 */
void changePlaceColumn(int valueY, float matrixAugmented[][valueY], int column1, int column2, int valueX){
    if(matrixAugmented == NULL || column1 < 0 || column2 < 0 || column1 == column2 || valueX <= 0 || column1 > valueX || column2 > valueX){
        return;
    }
    float value;
    int i = 0;
    for(i = 0; i < valueX; i++){
        value = matrixAugmented[i][column1];
        matrixAugmented[i][column1] = matrixAugmented[i][column2];
        matrixAugmented[i][column2] = value;
    }
}
