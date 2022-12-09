/**
* @file MatrixOps
* @description Bu program bazi matematiksel fonksiyonlarin gerceklesmesini saglar.
* @assignment 1.Odev
* @date 28.11.2022
* @author Ahmed Muaz Atik - ahmedmuaz.atik@stu.fsm.edu.tr
*/

#ifndef __MATRIXLIB_H__
#define __MATRIXLIB_H__

float *returnVector(int);

float **returnMatrix(int, int);

void freeMatrix(float **, int);

float mean(float *, int);

float correlation(float *, float *, int);

float covariance(float *, float *, int);

float **matrixMultiplication(float **, float **, int, int, int, int);

float **matrixTranspose(float **, int, int);

float **rowMeans(float **, int, int);

float **columnMeans(float **, int, int);

float **covarianceMatrix(float **, int, int);

float determinant(float **, int);

void printVector(float *, int);

void printMatrix(float **, int, int);

#endif
