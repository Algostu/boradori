#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
typedef struct people {
	int num;
	int weight;
}pe;
void weight(pe* str, int* arr,int N) {
	    
	for (int i = 0; i < N; i++) {
		(str + i)->weight = 0;
		for (int j = 0; j < N; j++)
			(str + i)->weight += arr[j];

	}

}

int what(pe* str,int n) {
	int max = 0;
	int max1 = 0;
	int max2 = 0;
	
	for (int i = 0; i < n; i++) {
		if (str[i].num == 1)
			max1 += str[i].weight;
		if (str[i].num == 2)
			max2 += str[i].weight;
		
	}
	if (max1 > max2)
		return 1;
	else if (max2 > max1)
		return 2;
	else
		return 1;
}

int main() {
	int** arr;
	pe* str;
	int N = 0, max = 0, sum = 0;
	scanf("%d", &N);
	str = (pe*)malloc(N * sizeof(pe));
	arr = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		*(arr + i) = (int*)malloc(N * sizeof(int));
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &str[i].num);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		weight(str, *(arr + i), N);
	}
	max = what(str, N);

	for (int i = 0; i < N; i++) {
		if (str[i].num == 0)
			str[i].num = max;
	}
	for (int i = 0; i < N; i++) {
		
			for (int j = i; j < N; j++) {
				if (str[i].num!= str[j].num)
					sum += arr[i][j];
			}
		
	}
	printf("%d\n", sum);
	for (int i = 0; i < N; i++) {
		if(str[i].num==1)
			printf("%d ",i+1);
	}
	printf("\n");
	for (int i = 0; i < N; i++) {
		if (str[i].num == 2)
			printf("%d ", i + 1);
	}
}