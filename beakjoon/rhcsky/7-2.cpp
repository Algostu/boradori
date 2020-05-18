#include <iostream>
using namespace std;
const int MAX=10001;

int self_number(int);

int main()
{
    int num;
    bool res[MAX] ;
    fill_n(res,sizeof(res),true);
    
    for (int i = 0; i < MAX; i++)
    {
        num = self_number(i);
        if (num > MAX) continue;
        res[num] = false;
    }

    for (int i = 0; i < MAX; i++)
    {   
        if(res[i])
            cout << i << endl;
    }
    
    return 0;
}


int self_number(int i){
    int num = i;
    
    do
    {
        num += i%10;
    } while ((i/=10) != 0);
    
    return num;
}