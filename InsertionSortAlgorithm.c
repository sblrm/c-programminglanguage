#include <stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print(int arr[], int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d\n", arr[i]);
	}
	printf("\n");
}

void insertionSort(int arr[], int size){
	int i, j, key;
	
	for(i = 1; i < size; i++){
		key = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int main(){

	int arr[] = {5, 3, 8, 4, 2, 9, 1};
	int size = sizeof(arr) / sizeof(int);
	
	insertionSort(arr, size);
	print(arr, size);

return 0;

}

