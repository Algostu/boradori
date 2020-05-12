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

    scanf("%s", arr);

    for(int i = 0; i<strlen(arr);i++){
        if(arr[i] <= 'Z' && arr[i] >= 'A') {
          if(++alpha[arr[i] - 'A'] > max) {
            max = alpha[arr[i] - 'A'];
            if(max > strlen(arr) / 2) {
              cout << arr[i];
              return;
            }
          }
        }
        else {
          if(++alpha[arr[i] - 'a'] > max){
            max = alpha[arr[i] - 'a'];
            if(max > strlen(arr) / 2){
              printf("%c", arr[i] + 'A' - 'a');
              return;
            }
          }
        }

    }

    max = 0;

    for(int i = 0; i < 28; i++){
        if(alpha[i] > max) {max = alpha[i]; max_word = 'A' + i;}
    }

    for(int i = 0; i<28;i++){
        if(alpha[i] == max) count++;
    }

    for(auto elem : alpha){
      cout << elem;
    }

    if(count==1){
        cout << max_word;
    } else{
        cout << '?';
    }

}
