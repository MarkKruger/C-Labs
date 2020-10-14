#include <iostream>
float fast_sqrt(int n);


int main(){

	float sqrt_array[4][4];
	float sqrt_arr[16]; 

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			sqrt_array[i][j] = fast_sqrt(i+j+1);
		}
	}

	int k = 0;
	for (int i = 3; i >= 0; i--){
		for (int j = 0; j < 4; j++){
			sqrt_arr[k] = sqrt_array[i][j];
			k++;
		}
	}

	std::cout << std::fixed;
	std::cout.precision(2);
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			std::cout << sqrt_array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout.precision(4);
	for (int i = 0; i < 16; i++){
		std::cout << sqrt_arr[i] << " ";
	}
	
	
	return 0;
}

float fast_sqrt(int n){

	asm("finit"); 
	asm("fild dword ptr[ebp+8]"); 
	asm("fsqrt"); 
	asm("fstp dword ptr[ebp-4]"); 
	return ret_v; 
}


