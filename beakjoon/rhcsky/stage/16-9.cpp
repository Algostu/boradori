#include <iostream>
using namespace std;

int main() {
    int n, ans = 9;
    int arr[2][12] = {0,};

    scanf("%d", &n);
    
    for(int i = 2; i < 11; i++)
        arr[1][i] = 1;
    
    for(int i = 2; i <= n; i++) {
        ans = 0;
        for(int j = 1; j < 11; j++) {
            arr[i%2][j] = (arr[(i-1)%2][j-1] + arr[(i-1)%2][j+1]) % 1000000000;
            ans = (ans + arr[i%2][j]) % 1000000000;
        }
    }
    
    cout << ans;
    
    return 0;
}