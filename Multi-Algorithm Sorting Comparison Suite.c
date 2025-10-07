#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void assignRandomNumber(int array[], int size);
void printArray(int array[], int size);
void swap(int *a, int *b);

void BubbleSort(int array[], int size);
void SelecionSort(int array[], int size);
void InsertionSort(int array[], int size);


int main()
{
	int array[8];
	int size = sizeof(array)/sizeof(array[0]);
	
	assignRandomNumber(array,size);
	
	
	printf("unsorted : ");
	printArray(array, size);
	
	printf("sorted : ");
//	BubbleSort(array, size);
//	SelectionSort(array, size);
	InsertionSort(array, size);
	
	printArray(array,size);
	
	return 0;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void assignRandomNumber(int array[], int size)
{
	time_t t;
	srand((unsigned) time(&t));
	int i;
	for(i = 0; i < size; i++)
	{
		array[i] = rand() % 100;
	}
}

void printArray(int array[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
void BubbleSort(int array[], int size)
{
	int i, j;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size - 1 - i; j++)
		{
			if(array[j] > array[j+1])
				swap(&array[j], &array[j+1]);
				
		}
	}
}

void SelecionSort(int array[], int size)
{
	int i, j;
	for(i = 0; i < size; i++)
	{
		int minIndex = i;
		for(j = i+1; j < size; j++)
		{
			if(array[minIndex] > array[j])
				minIndex = j;
		}
		swap(&array[i], &array[minIndex]);
	}
}
void InsertionSort(int array[], int size)
{
	int i, j;
	for(i = 1; i < size; i++)
	{
		int temp = array[i];
		j = i -1;
		while(j >= 0 && array[j] > temp)
		{
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = temp;
	}
}
