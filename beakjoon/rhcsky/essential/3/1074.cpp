#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, r, c, res=0;
	cin >> N >> r >> c;

	while (N--) {
		if (r >= 1 << N) {
			res += (1 << N) * (1 << N) * 2;
			r -= (1 << N);
		}
		if (c >= 1 << N) {
			res += (1 << N) * (1 << N);
			c -= (1 << N);
		}
	}
	cout << res << endl;
	return 0;
}


int mymain()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,r,c;
    int row, col;

    cin >> n >> r >> c;
    
    if(r&1){
        row = int(r/2) * (pow(2,n-1) * 4) + 3;
    }
    else{
        row = int(r/2) * (pow(2,n-1) * 4) + 1;
    }

    if(c&1){
        col = int(c/2) * 4 + 1;
    }
    else{ 
        col = int(c/2) * 4 + 0;
    }
    cout << row + col - 1 << endl;

    return 0;
}