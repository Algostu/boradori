#include <bits/stdc++.h>

using namespace std;

int GCD(int A, int B){
	if (A < B) swap(A, B);
	
	while(B != 0){
		int r = A % B;
		A = B;
		B = r;
	}
	
	return A;
}

int LCM(int A, int B){
	return A * B / GCD(A, B);
}

void solve(){
	int A, B;
	
	cin >> A >> B;
	
	// 최소공배수 구하기
	int lcm = LCM(A, B); 
	
	printf("%d\n", lcm);
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int T;
	
	cin >> T;
	
	for (int i = 0; i<T; i++){
		solve();
	}

	return 0;
}

