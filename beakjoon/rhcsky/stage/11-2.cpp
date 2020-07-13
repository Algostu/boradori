#include <iostream>
using namespace std;

int Fibonachi(int);

int main()
{
    int num;
    cin >> num;
    cout << Fibonachi(num);    

    return 0;
}

int Fibonachi(int a){
    if(a==0) return 0;
    if(a==1 || a==2) return 1;
    
    return Fibonachi(a-1) + Fibonachi(a-2);
}