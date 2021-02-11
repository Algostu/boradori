// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

void makeSegmentTree(vector<int> &source, vector<int> &sg_tree, int node, int start, int end){
    if(start==end) sg_tree[node] = source[start];
    else{
        int mid = (start+end)/2;
        makeSegmentTree(source, sg_tree, node*2, start, mid);
        makeSegmentTree(source, sg_tree, node*2+1, mid+1, end);
        int left = sg_tree[node*2];
        int right = sg_tree[node*2+1];
        sg_tree[node] = min(left, right);
    }
}

int intervalSum(vector<int> &sg_tree, int node, int start, int end, int left, int right){
    if(right < start or end < left) return 1000000000;
    else if( left <= start and end <= right) return sg_tree[node];
    else {
        int mid = (start+end)/2;
        return min(intervalSum(sg_tree, node*2, start, mid, left, right), 
                        intervalSum(sg_tree, node*2+1, mid+1, end, left, right));
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    int sg_size = 1 << (int)(ceil(log2(N)+1e-9) + 1);
    vector<int> arr(N);
    vector<int> sg_tree(sg_size);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    makeSegmentTree(arr, sg_tree, 1, 0, N-1);

    for(int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", intervalSum(sg_tree, 1, 0, N-1, a-1, b-1));
    }
}