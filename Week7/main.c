#define LONG_N 100
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int cmp(const void*a, const void*b)//ascending order
{
	return *(int*)a - *(int*)b;
}

void Mysort(int array[], int length){
	
	for(int i = 0; i < length; i++){
		int key = array[i];
		int j = i - 1;
		while( j >= 0 && key < array[j]){
			array[j+1] = array[j];
			j--;
			
		}
		array[j+1] = key;
	}

}
int main()
{
	int i;
	int array_long[LONG_N];
	int num = 0;
	scanf("%d", &num);

	while (num--)
	{
		for (i = 0; i < LONG_N; ++i)
		{
			array_long[i] = (int)(rand());
		}
		int array_long_target[LONG_N];
		int array_long_test[LONG_N];
		memcpy(array_long_target, array_long, LONG_N * sizeof(int));
		memcpy(array_long_test, array_long, LONG_N * sizeof(int));
		qsort(array_long_target, LONG_N, sizeof(int), cmp);
		Mysort(array_long_test, LONG_N);
		for (i = 0; i < LONG_N; ++i)
		{
			printf("%d ", array_long_test[i] - array_long_target[i]);
		}	
		printf("\n");
	}
	return 0;
}
