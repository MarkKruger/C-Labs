//		  Функция strncat. 
//        Формат char* strncat(char* dest, const char* src, size_t maxlen). 
//        Функция приписывает maxlen символов строки src к строке dest. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* strncat (char* dest, char* src, size_t maxlen){
	
	size_t new_size = 5 + maxlen;
	dest = (char *) realloc (dest, new_size);

	if (!dest){
		puts("Realloc failed");
		exit(1);
	}
	
	char *array;
	array = (char *) malloc(maxlen);
	if (!array){
		exit(1);
	}


	for (int i = 0; i < maxlen; i++){
		*(array + i) = *(src + i); 
	}
	
	strcat(dest,array); 
	free(array); 
	return dest; 
}


int main(){
	char *dest;
	char *src;
	short dest_size;
	dest = (char *) malloc (5);
	src = (char *) malloc (5);
	size_t maxlen;


	puts("Input dest and src");
	scanf("%s %n",dest, &dest_size);
	scanf("%s",src);
	puts("Input maxlen");
	scanf("%d", &maxlen);
	

	char *a;
	a = (char *) malloc(maxlen + 5);
	if (!a){
		exit(1);
	}

	a = strncat(dest,src,maxlen);
	puts("\n");
	dest_size += maxlen - 1;
	for (int i = 0; i < dest_size; i++){
		printf("%c",a[i]);
	}
	
	
	free(dest);
	free(src);
	free(a);
	return 0;
}
