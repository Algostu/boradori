#include <bits/stdc++.h>
using namespace std;

set<int> s;
inline void addX(int x){
    s.insert(x);
}

inline void removeX(int x){
    s.erase(x);
}

inline void checkX(int x){
    if(s.find(x)!=s.end()) cout << 1 << '\n';
    else cout << 0 << '\n';
}

inline void toggleX(int x){
    if(s.find(x)!=s.end()) s.erase(x);
    else s.insert(x);
}

inline void allS(){
    s.clear();
    for (int i = 0; i < 21; i++){s.insert(i);}
}

inline void emptyS(){
    s.clear();
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N,x;
    string q;

    cin >> N;
    cin.ignore();
    while (N--)
    {
        cin >> q;
        if (q == "add")
        {
            cin >> x;
            addX(x);
        }
        else if (q == "remove")
        {
            cin >> x;
            removeX(x);
        }
        else if (q == "check")
        {
            cin >> x;
            checkX(x);
        }
        else if (q == "toggle")
        {
            cin >> x;
            toggleX(x);
        }
        else if (q == "all")
        {
            allS();
        }
        else if (q == "empty")
        {
            emptyS();
        }
    }
    return 0;
}