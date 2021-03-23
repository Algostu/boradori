#include <bits/stdc++.h>

using namespace std;

void solve(){
	long long int x = 0;
	int n, alpha;
	int row, col;
	
	cin >> x;
	
	n = int(sqrt(2*x)) - 1;
	
	n = ((n+1)*(n+2) / 2 > x ? n : n+1);
	
	alpha = x - (n*(n+1) / 2);
	
	if (alpha==0){
		if (n % 2 != 0){
			row = 1;
			col = n;
		} else {
			row = n;
			col = 1;
		}
	} else {
		n++;
		if (n % 2 == 0){
			row = alpha;
			col = n - alpha + 1;
		} else {
			row = n - alpha + 1;
			col = alpha;
		}
	}
	
	printf("%d/%d\n", row, col);
	
	return;
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	solve();

	return 0;
}

