#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int llu;

void solve(){
    llu n; 
    llu max_val;
    llu height[100000];
    llu left_to_right[100000];
    llu right_to_left[100000];
    stack<llu> st;
    cin >> n;

    while(n!=0){
        max_val = 0;
        for(int i = 0; i<n; i++){
            scanf("%lld", height+i);
        }

        st.push(0);
            
        for(llu i = 1; i<n; i++){
            while(!st.empty() and height[st.top()] > height[i]){
                llu local_max_val = height[st.top()] * (i - st.top()); 
                left_to_right[st.top()] = local_max_val;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            llu local_max_val = height[st.top()] * (n - st.top());
            left_to_right[st.top()] = local_max_val;
            st.pop();
        }
       
        st.push(n-1);
            
        for(int i = n-2; i>=0; i--){
            while(!st.empty() and height[st.top()] > height[i]){
                llu local_max_val = height[st.top()] * (st.top() - i); 
                right_to_left[st.top()] = local_max_val;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            llu local_max_val = height[st.top()] * (st.top() + 1);
            right_to_left[st.top()] = local_max_val;
            st.pop();
        }

        for(int i=0; i<n; i++){
            llu local_max_val = left_to_right[i] + right_to_left[i] - height[i];
            if (max_val < local_max_val){
                max_val = local_max_val;
            }
        }

        cout << max_val << endl;

        cin >> n;
    }
    return;
}

int main(void){

    solve();

    return 0;
}
