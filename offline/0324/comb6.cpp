// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<char> arr = {'a', 'b', 'c', 'd', 'e'};
    vector<bool> tmp(arr.size(), true);
    int r = 3;
    for(int i=0; i<arr.size() - r; i++) tmp[i] = false;
    do{
        for(int i=0; i<arr.size(); i++){
            if(tmp[i])
                cout << arr[i] << " ";
        }
        cout << endl;
    } while(next_permutation(tmp.begin(), tmp.end()));

    return 0;
}