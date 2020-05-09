#include <iostream>
#include <cstring>

using namespace std;

void solve(int n);

int main(void){
    int i, n;
    cin >> n;

    for(i=0;i<n;i++){
        solve(i+1);
    }
}

void solve(int n){
    int R;
    char arr[20];

    cin >> R >> arr;
    for(int j = 0; j<strlen(arr); j++){
        for(int i = 0; i<R;i++){
            cout << arr[j];
        }
    }
    cout << endl;
}