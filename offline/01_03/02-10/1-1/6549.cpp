#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int llu;

void makeSegmentTree(vector<int> &source, vector<int> &sg_tree, int node_idx, int start, int end){
    if(start == end){
        sg_tree[node_idx] = start;
    } else {
        int mid = (start+end) / 2;
        makeSegmentTree(source, sg_tree, node_idx * 2, start, mid); 
        makeSegmentTree(source, sg_tree, node_idx * 2 + 1, mid+1, end); 
        int left_arg = sg_tree[node_idx*2];
        int right_arg = sg_tree[node_idx*2+1];
        sg_tree[node_idx] = (source[left_arg] > source[right_arg]) ? right_arg : left_arg;
    }
}

int intervalMin(vector<int> &source, vector<int> &sg_tree, int node_idx, int start, int end, int left, int right){
    if (right < start or end < left){
        return -1;
    } else if (left <= start and end <= right){
        return sg_tree[node_idx];
    } else {
        int mid = (start+end)/2;

        int left_arg = intervalMin(source, sg_tree, node_idx*2, start, mid, left, right);
        int right_arg = intervalMin(source, sg_tree, node_idx*2+1, mid+1, end, left,right);

        if(left_arg == -1){
            return right_arg;
        } else if (right_arg == -1){
            return left_arg;
        } else {
            return (source[left_arg] > source[right_arg]) ? right_arg : left_arg; 
        }
    }
}

llu findLargestSize(vector<int> &heights, vector<int> &sg_tree, int start, int end){
    int h_m = intervalMin(heights, sg_tree, 1, 0, heights.size()-1, start, end);

    llu max_size = (long long)heights[h_m] * (long long)(end - start + 1);

    if(start <= h_m-1){
        llu left_max_size = findLargestSize(heights, sg_tree, start, h_m-1);
        if (max_size < left_max_size){
            max_size = left_max_size;
        }
    }
    if(h_m+1 <= end){
        llu right_max_size = findLargestSize(heights, sg_tree, h_m+1, end);
        if (max_size < right_max_size){
            max_size = right_max_size;
        }
    }
    return max_size;
}

int main(void)
{
    while (1){
        int N, sg_size;
        cin >> N;
        if(N == 0) break;
        sg_size = (int)(ceil(log2(N) + 1e-9) + 1);
        sg_size = 1 << sg_size;
        vector<int> heights(N);
        vector<int> sg_tree(sg_size);
        for(int i=0; i<N; i++){
            scanf("%d", &heights[i]);
        }
        makeSegmentTree(heights, sg_tree, 1, 0, N-1);
        cout << findLargestSize(heights, sg_tree, 0, N-1) << endl;
        //solve();
    }
    return 0;
}
