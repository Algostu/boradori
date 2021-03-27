// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

void comb(vector<pair<int, bool>> arr, vector<char> pick, int index, int depth){
    if(depth == pick.size()){
        for(auto & it : pick){
            cout << it << " ";
        }
        cout << endl;
    } else {
        for(int i=index; i<arr.size(); i++){
            if(arr[i].second) continue;

            arr[i].second = true;
            pick[depth] = arr[i].first;
            comb(arr, pick, i+1, depth+1);
            arr[i].second = false;
        }
    }
}

int main() {
    vector<char> arr = {'a', 'b', 'c', 'd', 'e'};
    vector<pair<int, bool>> check;
    for(auto & elem : arr){
        check.push_back({elem, false});
    }
    vector<char> pick(3);
    int r = 3;
    comb(check, pick, 0, 0);
    return 0;
}