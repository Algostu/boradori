// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

void makeSegmentTree(vector<int> &source, vector<pair<int, int>> &sg_tree, int node, int start, int end){
    if(start==end) {
        sg_tree[node].first = sg_tree[node].second = source[start];
    }
    else{
        int mid = (start+end)/2;
        makeSegmentTree(source, sg_tree, node*2, start, mid);
        makeSegmentTree(source, sg_tree, node*2+1, mid+1, end);
        pair<int, int> left = sg_tree[node*2];
        pair<int, int> right = sg_tree[node*2+1];
        sg_tree[node].first = min(left.first, right.first);
        sg_tree[node].second = max(left.second, right.second);
    }
}

pair<int, int> intervalMinMax(vector<pair<int, int>> &sg_tree, int node, int start, int end, int left, int right){
    if(right < start or end < left) return make_pair(1000000000, 0);
    else if( left <= start and end <= right) return sg_tree[node];
    else {
        int mid = (start+end)/2;
        pair<int, int> left_ = intervalMinMax(sg_tree, node*2, start, mid, left, right);
        pair<int, int> right_ = intervalMinMax(sg_tree, node*2+1, mid+1, end, left, right);
        return make_pair(min(left_.first, right_.first), max(left_.second, right_.second));
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    int sg_size = 1 << (int)(ceil(log2(N)+1e-9) + 1);
    vector<int> arr(N);
    vector<pair<int, int>> sg_tree(sg_size, make_pair(0, 0));
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    makeSegmentTree(arr, sg_tree, 1, 0, N-1);

    for(int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        pair<int, int> min_max = intervalMinMax(sg_tree, 1, 0, N-1, a-1, b-1);
        printf("%d %d\n", min_max.first, min_max.second);
    }
}