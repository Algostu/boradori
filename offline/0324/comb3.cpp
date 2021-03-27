// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

void comb(vector<char> arr, vector<char> pick, int index, int depth){
    if(depth == pick.size()){
        for(auto & it : pick){
            cout << it << " ";
        }
        cout << endl;
    } else {
        for(int i=index; i<arr.size(); i++){
            pick[depth] = arr[i];
            comb(arr, pick, i+1, depth+1);
        }
    }
}

int main() {
    vector<char> arr = {'a', 'b', 'c', 'd', 'e'};
    vector<char> pick(3);
    int r = 3;
    comb(arr, pick, 0, 0);
    return 0;
}