#include <bits/stdc++.h>

using namespace std;

int main(void){ cout.tie(NULL); cin.tie(NULL); ios_base::sync_with_stdio(false);
    int N;
    string arr;
    cin >> N;
    cin >> arr;
    int a, b, c;
    a = atoi(arr.substr(0,1).c_str());
    b = atoi(arr.substr(1,1).c_str());
    for(int i=2; i<N; i++){
        char s = arr[i]; c = 0;
        if(s == '1'){
            c = a + b;
        }
        a = b;
        b = c;
    }
    cout << c << endl; 
}