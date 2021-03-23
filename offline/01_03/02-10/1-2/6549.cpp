#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int llu;

long long solve(vector<int> &arr){
    stack<int> st;

    for(int i=0; i<n; i++){
        int right = i;
        while(!st.empty() and arr[st.top()] > arr[i]){
            int height = 

int main(void){
    while(true){
        int n;
        cin >> n;
        vector<int> heights(n);
        if (n==0) break;
        for(int i=0; i<n; i++){
            scanf("%d", &heights[i]);
        }
        cout << solve(heights) << "\n";
    }
    return 0;
}
