#include <iostream>
#include <stack>

using namespace std;

int main() {
			
	while(1) {
		int n; 
		cin >> n;

		stack<long long> s;
		long long arr[100001] = {0, };
		long long ans = 0;
		if(n == 0)
			break;

		for(int i = 1; i <= n; i++)
			cin >> arr[i];
																		
		s.push(0);

		for(int i = 1; i <= n+1; i++) {
			while(!s.empty() && arr[s.top()] > arr[i]) {
				long long height = s.top();
				s.pop();
				long long x = i - 1 - s.top();
				ans = max(ans, x * arr[height]);
			}
			s.push(i);
		}
		cout << ans << '\n';	
	}	
	return 0;
}
