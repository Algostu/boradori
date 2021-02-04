#include <bits/stdc++.h>

using namespace std;

int memos[21][21][21];

void init_memo(){
	for(int i=0; i<21; i++){
		for(int j=0; j<21; j++){
			for(int k=0; k<21; k++){
				memos[i][j][k] = -987654321;
			}
		}
	}
}

int w(int a, int b, int c, int memo[21][21][21]){
//	printf("w(%d, %d, %d)\n", a, b, c);
	
	if (a <= 0 or b <= 0 or c <= 0) 
    	return 1;

	if (a > 20 or b > 20 or c > 20)
	    return w(20, 20, 20, memo);
	
	if (memo[a][b][c] != -987654321){
		return memo[a][b][c];
	}
		
	if (a < b and b < c)
	    return memo[a][b][c] = w(a, b, c-1, memo) + w(a, b-1, c-1, memo) - w(a, b-1, c, memo);
	
	return memo[a][b][c] = w(a-1, b, c, memo) + w(a-1, b-1, c, memo) + w(a-1, b, c-1, memo) - w(a-1, b-1, c-1, memo);
}

void solve(){
	
	int a, b, c;
	
	
	while(true){
		cin >> a >> b >> c;
		
		if(a==-1 and b==-1 and c==-1) return;
		
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c, memos));
	}
	
}

int main(){
	
	init_memo();
	
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	solve();

	return 0;
}

