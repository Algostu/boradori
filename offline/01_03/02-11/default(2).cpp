// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

void update(vector<long long int> &tree, int i, long long int num){
    int N = tree.size()-1;
    while(i<=N){
        tree[i] += num;
        if(i==N) break;
        i += (i & (-i));
    }
    return;
}

long long int sum(vector<long long int> &tree, int i){
    long long int val = 0;
    while(i>0){
        val += tree[i];
        i -= (i & -i);
    }
    return val;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<long long> arr(N+1);
    vector<long long> fenwick_tree(N+1);
    for(int i=0; i<N; i++){
        scanf("%lld", &arr[i+1]);
        update(fenwick_tree, i+1, arr[i+1]);
    }

    for(int i=0; i<M+K; i++){
        long long int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
    
        if(a==1){
            update(fenwick_tree, b, c-arr[b]);
            arr[b] = c;
        }
        else if(a==2){
            printf("%lld\n", sum(fenwick_tree, c) - sum(fenwick_tree, b-1));
        }
    }
    return 0;
}