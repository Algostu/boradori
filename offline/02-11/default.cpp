// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> &heights){
    int N = heights.size();
    long long int max_size = 0;
    stack<int> st;

    for(int i=0; i<N; i++){
        int right = i;
        while(!st.empty() and heights[st.top()] > heights[i]){
            int height = heights[st.top()];
            st.pop();
            int left = -1;
            if(!st.empty()){
                left = st.top();
            }
            int width = right - left - 1;
            long long local_size = (long long)height * (long long)width;
            if(max_size < local_size){
                max_size = local_size;
            }
        }
        st.push(i);
    }

    int right = N;
    while(!st.empty()){
        int height = heights[st.top()];
        st.pop();
        int left = -1;
        if(!st.empty()){
            left = st.top();
        }
        int width = right - left - 1;
        long long local_size = (long long)height * (long long)width;
        if(max_size < local_size){
            max_size = local_size;
        }
    }

    return max_size;
}

int main() {
    while(true){
        int N;
        cin >> N;
        if ( N == 0 ) break;
        vector<int> arr(N);
        for(int i=0; i<N; i++){
            scanf("%d", &arr[i]);
        }
        cout << solve(arr) << "\n";
    }
    return 0;
}