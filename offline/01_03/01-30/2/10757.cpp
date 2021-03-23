#include <bits/stdc++.h>

using namespace std;

void solve(){
	string A, B;
	int len_A, len_B;
	int idx;
	int carry=0;
	stack<char> result;
	
	cin >> A >> B;
	
	len_A = A.size();
	len_B = B.size();
	
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	
	for(idx=0; idx<min(len_A, len_B); idx++){
		int a = A.at(idx) - '0';
		int b = B.at(idx) - '0';
		int sum = a + b + carry;
		
		if(sum >= 10){
			sum = sum - 10;
			carry = 1;
		} else {
			carry = 0;
		}
		
		result.push(sum);
	}
	
	string longer = (len_A > len_B ? A : B);
	
	for(; idx<longer.length(); idx++){
		int sum = longer.at(idx) - '0' + carry;
		
		if(sum >= 10){
			sum = sum - 10;
			carry = 1;
		} else {
			carry = 0;
		}
		
		result.push(sum);
	}
	
	if(carry){
		result.push(1);
	}
	
	while(!result.empty()){
		printf("%d", result.top());
		result.pop();
	}
	
	printf("\n");
}

int main(){
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	solve();

	return 0;
}

