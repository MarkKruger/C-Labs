// Преобразование:  2D  >  1D.  Двумерный  массив  4х4  вещественных  чисел  необходимо  
//        выложить в один ряд по элементам слева направо и снизу вверх. 
//        Инициализация: заполнить массив числами x[i][j] = v(i + j + 1). 
//        Вывод  на  экран:  каждый  элемент  одномерного  массива  вывести  с  точностью  четыре  
//        знака после запятой; каждый элемент двумерного массива – с точностью два знака. 

//                      [      1    1.41      1.73         2 
//                        1.41      1.73         2     2.24 
//                        1.73          2    2.24      2.45 
//                            2     2.24     2.45      2.65         ] 
//
//                                                            => 
//
//         [2 2.2361 2.4495 2.6458 1.7321 2 2.2361 2.4495 1.4142 1.7321 2 2.2361 1 1.4142 1.7321 2] 

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	float **sqrt_array = (float**) malloc(4 * sizeof(float*));
	for (int i = 0; i < 4; i++){
		*(sqrt_array + i) = (float*) malloc(4 * sizeof(float));
	}
	float *sqrt_arr = (float*) malloc(16 * sizeof(float));

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			*(*(sqrt_array + i) + j) = sqrt(i+j+1);
		}
	}

	int k = 0;
	for (int i = 3; i >= 0; i--){
		for (int j = 0; j < 4; j++){
			*(sqrt_arr + k)  = *(*(sqrt_array + i) + j);
			k++;
		}
	}

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			printf("%.2f ", *(*(sqrt_array + i) + j));
		}
		puts("\n");
	}
	
	for (int i = 0; i < 16; i++){
		printf("%.4f ",*(sqrt_arr + i));
	}
	

	for (int i = 0; i < 4; i++){
		free(*(sqrt_array + i));
	}
	free(sqrt_array);
	free(sqrt_arr);
	return 0;
}
