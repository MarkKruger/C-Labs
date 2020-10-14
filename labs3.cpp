#include <iostream>
#include <stdlib.h>
#include <string.h>

float fast_sqrt(int n);

char* strncat (char* dest, char* src, size_t maxlen){
	
	size_t new_size; 
	new_size = sizeof(dest); 
	new_size += maxlen;
	dest = (char *) realloc (dest, new_size);
	if (!dest){
		std::cout << "Realloc failed";
		exit(1);
	}
	
	char *array;
	array = (char *) malloc(maxlen);
	for (int i = 0; i < maxlen; i++){
		array[i] = src[i]; 
	}
	
	strcat(dest,array); 
	free(array); 
	return dest; 
}


int main(){
	
	
	std::cout << std::endl;
	std::cout << std::endl;
	
	char *dest;
	char *src;
	dest = (char *) malloc(5); 
	src = (char *) malloc(5);
	size_t maxlen;
	std::cout << "Input dest" << std::endl;
	std::cin >> dest;
	std::cout << "Input src" << std::endl;
	std::cin >> src;
	std::cout << "Input maxlen" << std::endl;
	std::cin >> maxlen;
	
	char *a;
	a = (char *) malloc(maxlen + 5);
	if (!a)
	{
	exit(1);
	}
	a = strncat(dest,src,maxlen);
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << a;
	free(dest);
	free(src);
	free(a);
	
	return 0;
}

float fast_sqrt(int n){

	float ret_v;
	asm("finit"); 
	asm("fild dword ptr[ebp+8]");
	asm("fsqrt"); 
	asm("fstp dword ptr[ebp-4]"); 
	return ret_v; 
}


