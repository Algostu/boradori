#include <iostream>
#include <math.h>
using namespace std;

double CalDistance(int x1, int y1, int x2, int y2){
    return (double)sqrt(pow(abs(x1-x2),2) + pow(abs(y1-y2),2));
}

int main()
{
    double x1,y1,r1,x2,y2,r2,distance;
    int test;
    cin >> test;
    while(test--){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        distance = CalDistance(x1,y1,x2,y2);

        if(distance == 0){
            if(r1==r2) cout << -1 << endl;
            else cout << 0 << endl;
        }
        else{
        if(distance < r1+r2 && distance > abs(r1-r2)) cout << 2 << endl;
        else if(distance == abs(r1-r2) || distance == r1+r2) cout << 1 << endl;
        else cout << 0 << endl;
        }
    }
    return 0;
}