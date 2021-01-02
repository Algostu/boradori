#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define COMPARE(X, Y) (X > Y) ? (Y) : ((X) == (Y) ? (Y) : (X))

typedef struct _gasungbi{
	double point;
	int num;
} gasungbi;

int sort_key(const void* a, const void* b){
	return (*(gasungbi*)a).point - (*(gasungbi*)b).point;
}

double avg(int* arr, size_t size){
	int i, sums=0;
	for(i=0;i<size;i++){
		sums += arr[i];
	}
	return (double)sums / size;
}

void solve(int test_num){
	int i, j, N, K, P, ans = 0;
	int beauti[50][30];
	gasungbi arr[1500];
	
	scanf("%d %d %d", &N, &K, &P);
	
	for(i=0;i<N;i++){
		for(j=0;j<K;j++){
			scanf("%d", &beauti[i][j]);
			arr[i*K+j].point = avg(beauti[i], j+1);
			arr[i*K+j].num = j+1;
		}
	}
	
	for(i=0;i<K*N;i++){
		printf("[%d] : %f * %d \n", i+1, arr[i].point, arr[i].num);
	}
		
	printf("Case #%d: %d\n", test_num, ans);
}

int main(void){
	int i, n;
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		solve(i+1);	
	}
	
	return 0;
}