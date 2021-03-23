// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

void myComp(vector<int> a, vector<int> A, int N, int i, int s, int c){
    if(

int main() {
    int N, C;
    vector<int> a, b, A, B;
    A.reserve(40000); B.reserve(40000);
    cin >> N >> C;
    for(int i=0; i<N; i++){
        int tmp; cin >> tmp;
        if(i<N/2) a.push_back(tmp);
        else b.push_back(tmp);
    }
    sort(a); sort(b);
    myComp(a, A); sort(A);
    myComp(b, B); sort(B);

    int i, j, s, cnt;
    i = s = cnt = 0; j=N-(N/2);
    while(i<(N/2)){
        s = A[i] + B[j];
        if(s < C or j==0) i++;
        else j--;
        if(s < C) cnt += j;
    }
    cout << cnt << "\n";
    return 0;
}