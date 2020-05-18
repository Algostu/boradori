#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int a_n(int n){
	int i, ans=0;
	
	for(i=0;i<n;i++){
		ans += (i+1);
	}
	
	return ans;
}


void solve(int test_num){
	int X, i=2;
	scanf("%d", &X);
	
	if(X == 1){
		printf("1/1");
	}
	
	while(1){
		if(a_n(i) >= X) {
			if(i % 2 == 0)
		printf("%d/%d", X - a_n(i-1),(a_n(i)-X)+1); 
		else printf("%d/%d",(a_n(i)-X)+1 , X - a_n(i-1)); 
		
		break;}
		i++;
	}
	
}

int main(void){
	solve(0);
	return 0;
}