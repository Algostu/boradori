#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int sort_key(const void * a, const void * b){
	return *(int*)a - *(int*)b;	
}

void solve(int test_num){
	int i, B, A[1000], N, count =0, cost=0;
	scanf("%d %d", &N, &B);
	for(i=0;i<N;i++){
		scanf("%d", A+i);
	}
	
	qsort(A, N, sizeof(int), sort_key);
	
	for(i=0;i<N;i++){
		printf("A[%d] : %d\n", i, A[i]);
	}
	
	while(count<N){
		if(cost + A[count] > B) break;
		cost += A[count++]; 
	}
	
	printf("Case #%d: %d\n", test_num, count);
}

int main(void){
	int i, n;
	
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		solve(i+1);	
	}
	
	return 0;
}