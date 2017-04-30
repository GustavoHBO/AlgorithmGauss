#include "methodGauss.c"
//void menu();
//int startProgram();
//float *returnArrayCoefficient(char* equation, int quant);

float* methodGauss(float* matrixAugmented, int valueX, int valueY);
void changePlaceLine(int valueY, float matrixAugmented[][valueY], int line1, int line2, int valueX);
void clearTerms(int valueY, float matrixAugmented[][valueY], int valueX);