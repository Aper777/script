#include <stdio.h>
#include <stdlib.h>

int **ptr_arr(int** array,int sizeN,int sizeM,int* new_size){
	int size_count = 0;
	for(int i = 0;i < sizeN;i++){
		for(int j = 0;j < sizeM;j++){
			if(array[i][j] % 2 == 0){
				size_count++;
				array[i] = NULL;
				break;
			}
		}
	}
	int size = sizeN - size_count;
	int** ptr = (int**)malloc(size * sizeof(int*));
	if(ptr == NULL){
		printf("Array no alocation!");	
		exit(EXIT_FAILURE);
	}
	for(int i = 0;i < size; i++){
		ptr[i] = (int*)malloc(sizeM * sizeof(int));
		if(ptr[i] == NULL){
			printf("Array no alocation!");	
			exit(EXIT_FAILURE);
		}
	}
	int k = 0;
	for(int i = 0;i < sizeN;i++){
		if(array[i] == NULL)continue;
		else{
			for(int j = 0;j < sizeM;j++){
				ptr[k][j] = array[i][j];
			}
			k++;
		}
	}
	*new_size = size;
	return ptr;
}

int main(){
	int N = 0;
	int M = 0;
	scanf(" %d %d",&N,&M);
	printf("ancanq\n");
	int** arr = (int**)malloc(N * sizeof(int*));
	if(arr == NULL){
		printf("Array no alocation!\n");	
		exit(EXIT_FAILURE);
	}
	for(int i = 0;i < N; i++){
		arr[i] = (int*)malloc(M * sizeof(int));
		if(arr == NULL){
			printf("Array no alocation!\n");	
			exit(EXIT_FAILURE);
		}
	}
	for(int i = 0;i < N;i++){
		for(int j = 0;j < M; j++){
			scanf("%d",&arr[i][j]);	
		}
		
	}
	printf("analiz\n");
	int new_size ;
	int** arrays =  ptr_arr(arr, N, M,&new_size);
	for(int i = 0; i < new_size;i++){
		for(int j = 0;j < M;j++){
			printf("%d",arrays[i][j]);
		}
		putchar(10);
	}
	free(arr);
	free(arrays);
	return 0;
}
