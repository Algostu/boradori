#include <iostream>
using namespace std;


bool is_han(int);

int main()
{      
    int num,cnt=0;
    cin >> num;
    for (int i = 1; i < num+1; i++)
    {
        if(is_han(i)) cnt++;
    }
    
    cout << cnt;

    return 0;
}

bool is_han(int a){

    if (a<100) return true;

    int temp = a/10;
    int gap = a%10 - temp%10;
    
    while (a>9)
    {    
        if (a%10 - temp%10 != gap) return false;

        a = temp;
        temp = a/10;      
    }
    return true;
}

