#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    // ascending sort
    sort(arr.begin(), arr.end());
    
    // init
    int f = 1;
    int num = arr[0];
    
    // make binary tree
    map<int, int> f_map;
    for(int i=1; i<n; i++){
        if(num == arr[i]){
            f+=1;
        } else {
            f_map[num] = f;
            f = 1;
            num = arr[i];
        }
    }
    
    f_map[num] = f;
    
    // print frequency
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int temp;
        scanf("%d", &temp);
        printf("%d ", f_map[temp]);
    }
    return 0;
}