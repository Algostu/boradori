// Created on 강한결의 iPad.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    multiset<int> s;
    for(int i=0; i<n; i++){
        int a;
        scanf("%d", &a);
        if(a!=0)
            s.insert(a);
        else{
            if(s.size() == 0){
                printf("0\n");
            } else {
                auto end = s.find(*s.rbegin());
                printf("%d\n", *(end));
                s.erase(end);
            }
        }
    }
    return 0;
}