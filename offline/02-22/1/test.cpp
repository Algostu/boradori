#include <bits/stdc++.h>

using namespace std;

int main(void){
    int arr[2][2];
    memset(arr[0], -1, sizeof(arr[0]));
    vector<int> vec(3, 3);
    fill(vec.begin(), vec.end(), 0);
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
            cout << arr[i][j] << " ";
    
    cout << endl;
    cout << sizeof(arr) << endl;
    cout << sizeof(arr[0]) << endl;
}
