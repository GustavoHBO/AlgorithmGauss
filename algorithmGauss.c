#include <stdlib.h>
#include <stdio.h>

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

void clearTerms(int valueX, float matrixAugmented[][valueX], int valueY){
    float valueMN = 0;
    int i = 0, j = 0, newLine = 0, k = 0;
    if(valueY == 0 || matrixAugmented == NULL){
        return;
    }
    for(i = 0; i < valueY; i++){
        newLine = i;
        while(matrixAugmented[i][i] == 0 && newLine + 1 < valueY){
            changePlaceLine(valueY, matrixAugmented, i, ++newLine, valueX);
        }
        if(newLine + 1 == valueY){
            i++;
            break;
        }
        for(k = 1; k + i < valueY; k++){
            valueMN = matrixAugmented[i+k][i] / matrixAugmented[i][i];
            for(j = 0; j < valueX; j++){
                matrixAugmented[i+k][j] -= valueMN * matrixAugmented[i][j];
            }
        }
    }
}

void systemResolution(int valueX, float matrixAugmented[][valueX], int valueY, float arrayResolution[valueX-1]){
    int i = 0, k =0;
    float value = 0;
    if(matrixAugmented[valueY-2][valueX-2] != 0 && matrixAugmented[valueY-2][valueX-1] !=0){
        arrayResolution[valueX-2] = matrixAugmented[valueY-2][valueX-1]/matrixAugmented[valueY-2][valueX-2];
    }
    else{
        arrayResolution[valueX-2] = 0;
    }

    for(i = valueY - 3; i >= 0; i--){
        value = 0;
        for(k = 0; k < valueY - 3 - i; k++){
            printf("%f\n", matrixAugmented[i][i+1]);
            printf("%f\n", arrayResolution[i+1-k]);
            value += matrixAugmented[i][i+1] * arrayResolution[i+1-k];
            printf("value %f\n", value);

        }
        printf("value2%f\n", value);
        arrayResolution[i] = (matrixAugmented[i][valueX-1] - value)/matrixAugmented[i][i];
    }
}