/**
* @file MatrixOps
* @description Bu program bazi matematiksel fonksiyonlarin gerceklesmesini saglar.
* @assignment 1.Odev
* @date 28.11.2022
* @author Ahmed Muaz Atik - ahmedmuaz.atik@stu.fsm.edu.tr
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrixLib.h"

int main(int num_of_arguements, char* args[]){

    if(num_of_arguements<2){
        return 0;
    }

    int seed = atoi(args[1]);
    
    srand(seed);
	
	printf("\n------ RETURN/PRINT VECTOR ------\n");
	
	printVector(returnVector(3),3);
	
	printf("\n\n------ RETURN/PRINT MATRIX ------\n");
	
	printMatrix(returnMatrix(3,3),3,3);
	
	printf("\n\n------ FREE MATRIX ------\n");
	
	printf("\n BEFORE: \n");
	
	float **newMat = returnMatrix(3,3);
	
	printMatrix(newMat,3,3);
	
	printf("\n AFTER: \n");
	
	freeMatrix(newMat,3);
	
	printMatrix(newMat,3,3);
	
	printf("\n\n------ MEAN ------\n");
	
	printf("Mean: %f", mean(returnVector(3),3));
	
	printf("\n\n------ CORRELATION ------\n");
	
	printf("Correlation: %f", correlation(returnVector(3),returnVector(3),3));
	
	printf("\n\n------ COVARIANCE ------\n");
	
	printf("Covariance: %f", covariance(returnVector(3),returnVector(3),3));
	
	printf("\n\n------ MATRIX MULTIPLICATION ------\n");
	
	printMatrix(matrixMultiplication(returnMatrix(3,3),returnMatrix(3,3),3,3,3,3),3,3);
	
	printf("\n------ MATRIX TRANSPOSE ------\n");
	
	printMatrix(matrixTranspose(returnMatrix(3,3),3,3),3,3);
	
	printf("\n------ ROW MEANS ------\n");
	
	printMatrix(rowMeans(returnMatrix(3,3),3,3),3,1);
	
	printf("\n------ COLUMN MEANS ------\n");
	
	printMatrix(columnMeans(returnMatrix(3,3),3,3),1,3);
	
	printf("\n------ COVARIANCE MATRIX ------\n");
	
	printMatrix(covarianceMatrix(returnMatrix(3,3),3,3),3,3);
	
	printf("\n------ DETERMINANT ------\n");
	
	printf("Determinant: %f", determinant(returnMatrix(3,3),3));
	
	return 0;
}
