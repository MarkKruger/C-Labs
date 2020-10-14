#include <iostream>

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
	std::cout << "Input start element" << std::endl;
	std::cin >> start_element;
	std::cout << "Input step" << std::endl;
	std::cin >> step;
	
	int output_array_size;
	count = process_array(array,array_size,start_element,step,output_array, &output_array_size);
	
	for (int i = 0; i < array_size; i++){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	
	std::cout << "Count = " << count << std::endl;
	
	for (int i = 0; i < output_array_size; i++){
		std::cout << output_array[i] << " ";
	}
	std::cout << std::endl;
	
	
	return 0;
}
