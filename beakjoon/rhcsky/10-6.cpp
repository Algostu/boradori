#include <iostream>
using namespace std;

int main()
{
    int x, y, w, h, Xmax, Ymax;
    cin >> x >> y >> w >> h;

    if(w-x>=x) Xmax = x;
    else Xmax = w-x;

    if(h-y>=y) Ymax = y;
    else Ymax = h-y;

    if(Xmax > Ymax) cout << Ymax;
    else cout << Xmax;

    return 0;
}