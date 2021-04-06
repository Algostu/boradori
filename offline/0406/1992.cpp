#include <bits/stdc++.h>

using namespace std;

char m[64][64];

void quad(int row, int col, int sz){
    char O = m[row][col], ssz=sz/2;
    bool f = true;
    for(int i=row; i<row+sz; i++) 
        for(int j=col; j<col+sz; j++) 
            if(O!=m[i][j]) f = false;
    if(f) cout << O;
    else {
        cout << "(";
        for(int i=0; i<2; i++) for(int j=0; j<2; j++) quad(row+i*ssz, col+j*ssz, ssz);
        cout << ")";
    }
    return;
}

int main(void){cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> m[i];
    quad(0, 0, n);
    return 0;
}