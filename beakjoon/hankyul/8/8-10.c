#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_group_word(char* arr, size_t size){
	int i;
	char alpha[26]={0};
	for(i=1;i<size;i++){
		if(arr[i] != arr[i-1]){
			if(alpha[arr[i-1]-'a']!=0) return 0;
			else alpha[arr[i-1] -'a']++;
		}
	}
	
	if(alpha[arr[size-1] - 'a']==1){
		return 0;
	} else{
		return 1;
	}
}

void solve(int test_num){
	int i, N, answer=0;
	char input_str[101];
	scanf("%d", &N);
	for(i=0;i<N;i++){
		scanf("%s", input_str);
	
		if(is_group_word(input_str, strlen(input_str))) answer++;
	}
	printf("%d", answer);
}

int main(){
	solve(0);
	
	return 0;	
}
