#include <bits/stdc++.h>

#define MAX_ARRAY 1000001

using namespace std;

void solve(){
    int N;
    int A[MAX_ARRAY];
    int NGE[MAX_ARRAY];
    int max_nge = -1;
    stack<int> st;

    cin >> N;

    for(int i=0; i<N; i++){
        scanf("%d", A+i);
    }

    NGE[N-1] = -1;
    st.push(A[N-1]);

    for(int i=N-2; i>=0; i--){
        while(!st.empty() and st.top() <= A[i]){
            st.pop();
        }

        if(!st.empty()){
            NGE[i] = st.top();
        }
        else{
            NGE[i] = -1;
        }

        st.push(A[i]);
    }
    
    for(int i=0; i<N; i++){
        printf("%d ", NGE[i]);
    }

    return;
}

int main(void){

    solve();

    return 0;
}
