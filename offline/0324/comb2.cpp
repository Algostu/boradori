// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

void comb(vector<char> arr, vector<char> pick, int r, int index, int depth){
    if(r==0){
        for(auto & it : pick){
            cout << it << " ";
        }
        cout << endl;
    } else if (depth == arr.size()){
        return;
    } else {
        pick[index] = arr[depth];
        comb(arr, pick, r-1, index+1, depth+1);
        comb(arr, pick, r, index, depth+1);
    }
}

int main() {
    vector<char> arr = {'a', 'b', 'c', 'd', 'e'};
    vector<char> pick(3);
    int r = 3;
    comb(arr, pick, 3, 0, 0);
    return 0;
}