#include <iostream>
#include <cstring>

using namespace std;

void solve(int n);

int main(void){
    int i, n;
    // cin >> n;

    // for(i=0;i<n;i++){
        solve(0);
    // }
}

void solve(int n){
    int alpha[28] = {0};
    char arr [1000002];
    int max = 0, count = 0;
    char max_word;
    cin >> arr;

    for(int i = 0; i<strlen(arr);i++){
        if(arr[i] <= 'Z' && arr[i] >= 'A') alpha[arr[i] - 'A']++;
        else alpha[arr[i] - 'a']++;
    }

    for(int i = 0; i < 28; i++){
        if(alpha[i] > max) {max = alpha[i]; max_word = 'A' + i;}
    }

    for(int i = 0; i<28;i++){
        if(alpha[i] == max) count++;
    }

    if(count==1){
        cout << max_word;
    } else{
        cout << '?';
    }
    
}