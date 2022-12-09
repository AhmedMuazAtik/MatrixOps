/**
* @file MatrixOps
* @description Bu program bazi matematiksel fonksiyonlarin gerceklesmesini saglar.
* @assignment 1.Odev
* @date 28.11.2022
* @author Ahmed Muaz Atik - ahmedmuaz.atik@stu.fsm.edu.tr
*/

#include "matrixLib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Girilen size boyutunda vektor dondurur.
float *returnVector (int size) {
	
	//Dinamik olarak bir vektor olusturuluyor.
	float *vector = (float *) malloc(size * sizeof(float));
	
	//Vektorun ici dolduruluyor.
	for (int i = 0; i < size; i++) {
		vector[i] = (rand() % 9) +1;
	}
	
	return vector;
}

//Girilen row ve col boyutunda matrix dondurur.
float **returnMatrix (int row, int col) {
	
	//Dinamik olarak matrix'in row'lari olusturuluyor.
	float **matrix = (float **) malloc(sizeof(float *) * row);
	
	//Matrix'in rowlarina colummnlar olusturuluyor.
	for (int i = 0; i < row; i++) {
		matrix[i] = (float *) malloc(sizeof(float) * col);
	}
	
	//Matrix'in ici dolduruluyor.
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = (rand() % 9) +1;
		}
	}
	
	return matrix;
}

//Girilen matrix'in heapta tuttugu yeri biraktirir.
void freeMatrix (float **mat, int row) {
	
	for (int i = 0; i < row; i++) {
    	free(mat[i]);
	}
	
	free(mat);
}

//Girilen vektor'un ortalamasini hesaplar.
float mean (float *vec, int size) {
	
	float avg = 0;
	
	//Tum degerleri avg'ye atiyor.
	for (int i = 0; i < size; i++) {
		avg += vec[i];
	}
	
	//Avg/size yapip cikan degeri avg'ye esitliyor.
	avg /= size;
	
	return avg;
}

//Iki vektor'un kovaryansi'ni hesaplar.
float covariance (float *vec1, float *vec2, int size) {
	
	float sum = 0;
	
	//Kovaryans denklemindeki toplama degerini buluyor.
	for (int i = 0; i < size; i++) {
		sum = sum + (vec1[i] - mean(vec1,size)) * (vec2[i] - mean(vec2,size));
	}
	
	//Kovaryans'i donduruyor.
	return sum / (size - 1);
}

//Iki vektor'un koralasyonu'nu hesaplar.
float correlation (float *vec, float *vec2, int size) {
	
	//Koralasyon denklemini uyguluyor.
	float correlation = covariance(vec,vec2,size) / 
		(sqrt(covariance(vec,vec,size)) * sqrt(covariance(vec2,vec2,size)));
				
	return correlation;
}

//Iki matrix'in carpimini dondurur.
float **matrixMultiplication (float **mat1, float **mat2, int row1, int col1, int row2, int col2) {
	
	//Dinamik olarak matrix olusturluyor.
	float **product = (float **) malloc(sizeof(float *) * col2);
	
	for (int i = 0; i < row1; i++) {
		product[i] = (float *) malloc(sizeof(float) * col2);
	}
	
	//Ilk matrix'in columnu ile ikinci matrix'in rowunun esitligine bakiliyor.
	if (col1 == row2) {
		
		//Matrix carpimi denklemi uygulaniyor.
		for (int i = 0; i < row1; i++) {
			for (int j = 0; j < col2; j++) {
				product[i][j] = 0;
				
				for (int k = 0; k < col2; k++) {
					product[i][j] += mat1[i][k]*mat2[k][j];
				}
			}
		}
		
	} else {
		printf("Ilk matrix'in columnu ile ikinci matrix'in rowu esit olmalidir.");	
	}
	
	return product;
}

//Girilen matrix'in transpozesi'ni aliyor.
float **matrixTranspose (float **mat, int row, int col) {
	
	//Dinamik olarak return edilecek matrix olusturuluyor.
	float **transpose = (float **) malloc(sizeof(float *) * col);
	
	for (int i = 0; i < row; i++) {
		transpose[i] = (float *) malloc(sizeof(float) * col);
	}
	
	//Transpoze islemi uygulaniyor.
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			transpose[i][j] = mat[j][i];
		}
	}
	
	return transpose;
}

//Girilen matrix'in rowlarinin ortalamasini hesaplar.
float **rowMeans (float **mat, int row, int col) {
	
	float total = 0;
	
	//Dinamik olarak return edilecek matrix olusturuluyor.
	float **avg = (float **) malloc(sizeof(float *) * row);
	
	for (int i = 0; i < row; i++) {
		avg[i] = (float *) malloc(sizeof(float) * 1);
	}
	
	//Row ortalamalari hesaplaniyor.
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			total += mat[i][j];
		}
		
		avg[i][0] = total / row;
		
		total = 0;
	}
	
	return avg;
}

//Girilen matrix'in columnlarinin ortalamasini hesaplar.
float **columnMeans (float **mat, int row, int col) {
	
	float total = 0;
	
	//Dinamik olarak return edilecek matrix olusturuluyor.
	float **avg = (float **) malloc(sizeof(float *) * 1);
	
	for (int i = 0; i < 1; i++) {
		avg[i] = (float *) malloc(sizeof(float) * col);
	}
	
	//Column ortalamalari hesaplaniyor.
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			total += mat[j][i];
		}
		
		avg[0][i] = total / row;
		
		total = 0;
	}
	
	return avg;
}

//Girilen matrix'in kovaryans matrix'i hesaplaniyor.
float **covarianceMatrix (float **mat, int row, int col) {
	
	float **covariance_matrix = returnMatrix(row,col);
	float **transpose = matrixTranspose(mat,row,col);
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			covariance_matrix[i][j] = covariance(transpose[i],transpose[i],col);
		}
	}
	
	return covariance_matrix;
}
	
//Girilen matrix'in determinanti'ni hesaplar.
float determinant (float **mat, int row) {
    
    int counter = 1;
    float det = 0;
    float sum = 0;
    float sub = 0;
    float val = 1;
    float temp_first = 1;
    float temp_second = 1;
    float temp_third = 1;
	
	//Matrix'in column sayisi arttiriliyor.
	for (int i = 0; i < 3; i++) {
	    mat[i] = realloc(mat[i], sizeof(float) * 5);
	}
	
	//Matrix'in ici dolduruluyor.
	for (int i = 0; i < 3; i++) {
	    for (int j = 0; j < 3; j++) {
	        mat[i][j] = val;
	        val++;
	    }
	}
	
	//Arttirilan columndaki degerler bastaki iki columnun degerlerine esitleniyor.
	for (int i = 0; i < 3; i++) {
		for (int j = 3; j < 5; j++) {
			mat[i][j] = mat[i][j-3];
		}
	}
	
	//Genisletilen matrix yazdiriliyor.
	for (int i = 0; i < 3; i++) {
	    for (int j = 0; j < 5; j++) {
	        printf("%f ", mat[i][j]);
	    }
	    printf("\n");
	}
	
	//Determinant hesaplamalari yapiliyor.
	for (int j = 0; j < 3; j++) {
	    temp_first *= mat[j][j];
	}
	
	for (int i = 0; i < 3; i++) {
	     temp_second *= mat[i][counter];
	     counter++;
    }
    
    counter = 2;
    
    for (int i = 0; i < 3; i++) {
        temp_third *= mat[i][counter];
        counter++;
    }
    
    //Pozitif kisim hesaplaniyor.
    sum = temp_first + temp_second + temp_third;
    
    temp_first = 1;
    temp_second = 1;
    temp_third = 1;
    
    counter = 0;
    
    for (int j = 2; j >= 0; j--) {
        temp_first *= mat[j][counter];
        counter++;
    }
    
    counter = 1;
    
    for (int i = 2; i >= 0; i--) {
        temp_second *= mat[i][counter];
        counter++;
    }
    
    counter = 2;
    
    for (int i = 2; i >= 0; i--) {
        temp_third *= mat[i][counter];
        counter++;
    }
    
    //Negatif kisim hesaplaniyor.
    sub = temp_first + temp_second + temp_third;
    
    //Determinant hesaplaniyor.
    det = sum - sub;
	
	return det;
}

//Girilen vector print ediliyor.
void printVector (float *vec, int N) {
	
	for (int i = 0; i < N; i++) {
		printf("%f ", vec[i]);
	}
}

//Girilen matrix print ediliyor.
void printMatrix (float **mat, int row, int col) {
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%f ", mat[i][j]);
		}
		
		printf("\n");
	}
}
