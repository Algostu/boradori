#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void solve(int n);

int main(void){
    int i, n;
	scanf("%d", &n);
    for(i=0;i<n;i++){
        solve(0);
    }
}

void solve(int n){
    int alpha[28] = {0};
    char arr [1000002];
    int max = 0, count = 0;
    char max_word;

    scanf("%s", arr);

    for(int i = 0; i<strlen(arr);i++){
        if(arr[i] <= 'Z' && arr[i] >= 'A') { 
			alpha[arr[i]-'A']++;
        } else {
			alpha[arr[i] - 'a']++;
		}

    }
	
	for(int i = 0; i<26;i++){
		if(max <= alpha[i]){
			if(max == alpha[i]) count++;
			else if(max < alpha[i]) count = 1;
			max = alpha[i];
			max_word = i + 'A';
		}
	}
	
	if(count == 1){
		printf("%c\n", max_word);
	} else{
		printf("?\n");
	}
}


