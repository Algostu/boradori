#include <bits/stdc++.h>

using namespace std;
typedef long long int lld;

lld makeSegmentTree(vector<lld> &source, vector<lld> &segment_tree, int node_number, int start, int end){
    // In this function, we use vector as tree structure. We can structure like this by using special node_number stratigy
    // Node X.node_number*2 == X.left.node_number
    // Node X.node_number*2 + 1 = X.right.node_number
    if (start == end){
        return segment_tree[node_number] = source[start]; // or end
    }

    int mid = (start + end) / 2;

    return segment_tree[node_number] = makeSegmentTree(source, segment_tree, node_number * 2, start, mid) + 
                                        makeSegmentTree(source, segment_tree, node_number * 2 + 1, mid+1, end);
}

lld intervalSum(vector<lld> segment_tree, int node_number, int start, int end, int left, int right){
    if(right < start || end < left){
        return 0;
    } else if ( left <= start and end <= right ){
        return segment_tree[node_number];
    } else {
        int mid = (start+end)/2;
        return intervalSum(segment_tree, node_number * 2, start, mid, left, right) + 
                intervalSum(segment_tree, node_number*2 + 1, mid+1, end, left, right);
    }
}

void updateSegmentTree(vector<lld> &segment_tree, int node_number, int start, int end, int target_node_idx, int diff){
    if(target_node_idx < start || end < target_node_idx) return;
    segment_tree[node_number] += diff;
    if(start != end){
        int mid = (start+end)/2;
        updateSegmentTree(segment_tree, node_number * 2, start, mid, target_node_idx, diff);
        updateSegmentTree(segment_tree, node_number * 2 + 1, mid+1, end, target_node_idx, diff);
    }
}

int main(void){
    vector<lld> source = {1, 2, 4, 5, 6, 7, 8, 9, 10};
    int source_size = source.size();
    int sg_tree_size = 1 << ((int)(ceil(log2(source_size)+1e-9))+1);
    cout << sg_tree_size << endl;
    vector<lld> sg_tree(sg_tree_size);

    makeSegmentTree(source, sg_tree, 1, 0, source_size-1);
    cout << intervalSum(sg_tree, 1, 0, source_size-1, 2, 8) << endl;
    updateSegmentTree(sg_tree, 1, 0, source_size-1, 8, 10);
    cout << intervalSum(sg_tree, 1, 0, source_size-1, 2, 8) << endl;
    return 0;
}

