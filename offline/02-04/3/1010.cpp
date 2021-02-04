#include <bits/stdc++.h>

using namespace std;

//long long int Factory(long long int start, long long int end){
//	long long int result = 1;
//	long long int operand = start;
//	
//	while(operand != end){
//		result *= operand;
//		operand--;
//	}
//	printf("Factory %d %d : %lld\n", start, end, result);
//	return result;
//}
//
//long long int Combination(int n, int r){
//	return Factory(n, n-r) / Factory(r, 1);
//}

long long int Combination(int n, int r, long long int memo[30][30]){
	if (n==r or r == 0){
		return 1;
	} else if (memo[n][r] != 0){
		return memo[n][r];
	} else {
		memo[n][r] = Combination(n-1, r-1, memo) + Combination(n-1, r, memo);
		return memo[n][r];
	}
}

void solve(){
	int N, M;
	
	cin >> N >> M;
	
	// Permutation ( M , N ) M개의 원소에서 N개의 원소를 순서대로 뽑는 경우의 수 구하기
	long long int memo[30][30];
	for (int i=0; i<30; i++){
		for(int j=0; j<30; j++){
			memo[i][j] = 0;
		}
	}
	long long int comb = Combination(M, N, memo);
	
	printf("%lld\n", comb);
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int T;
	
	cin >> T;
	
	for (int i=0; i<T; i++){
		solve();
	}
	

	return 0;
}

