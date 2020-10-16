//Объявить      массив   из    n=15   целых   чисел,   проинициализируйте   нулями.   Функция  
//processArray() должна  заполнить  массив  членами  арифметической  прогрессии  с  
//начальным элементом a1  и шагом d (ввести с клавиатуры), подсчитать и вернуть cnt – 
//количество  всех  двузначных  элементов  массива,  а  также  сформировать  выходной  
//массив, который содержит все элементы исходного, кроме тех, сумма цифр которых  
//равна 10. Вывести на экран массивы. 
//    	  Вход:
//        a1 = 7 d = 12 
//        [7 19 31 43 55 67 79 91 103 115 127 139 151 163 175] 

//        Выход:  
//        [7 31 43 67 79 103 115 139 151 175] 
//        cnt = 7 
        
#include <stdio.h>

int num_sum(int n){

	int sum = 0;
	while(n){
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int process_array(int* array, int array_size, int start_element, int step, int* output_array, int* out_arr_index){
	
	*array = start_element;
	int count = 0; 
	int element;
	for(int i = 1; i < array_size; i++){
		element = *(array+i-1)+ step;
		*(array + i) = element;
		if(element > 9 && element < 100){
			count++;
		}
	}
	
	int index = 0;
	for (int i = 0; i < array_size; i++){
		if (num_sum(*(array+i)) != 10){
			*(output_array + index) = *(array+i);
			index++;
		}
	}
	*out_arr_index = index;
	return count;
}


int main(){
	int array_element, count;
	int array_size = 15;
	int array[array_size];
	int output_array[array_size];
	
	for (int i = 0; i < array_size; i++){
		array[i] = 0;
	}
	
	int start_element, step;
	puts("Input start element");
	scanf("%d",&start_element);
	puts("Input step");
	scanf("%d",&step);
	
	int output_array_size;
	count = process_array(array,array_size,start_element,step,output_array, &output_array_size);
	
	for (int i = 0; i < array_size; i++){
		printf("%d ", array[i]);
	}
	puts("");

	printf("Count = %d\n", count);
	
	for (int i = 0; i < output_array_size; i++){
		printf("%d ", output_array[i]);
	}
	puts("");
	
	
	return 0;
}
