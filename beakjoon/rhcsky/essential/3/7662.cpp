#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    multiset<int> s;
    int T,N,x;
    string Q;
    cin >> T;
    while(T--){
        s.clear();
        cin >> N;
        while (N--)
        {
            cin >> Q >> x;
            if(Q=="I"){
                s.insert(x);
            }
            else{
                if(s.empty()) continue;

                if(x==1){//delete max
                    s.erase(--(s.end()));
                }
                else{
                    s.erase(s.begin());
                }
            }
        }
        if(s.empty()) cout << "EMPTY" << '\n';
        else{
            cout << *(s.rbegin()) << " " << *(s.begin()) << '\n';
        }
    }
    return 0;
}