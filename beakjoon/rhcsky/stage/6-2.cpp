#include <iostream>
using namespace std;

int main()
{
    int temp,max=0,index;
    
    for (int i = 0; i < 9; i++)
    {
        cin >> temp;
        if (temp>max)
        {
            max = temp;
            index = i;
        }        
    }
    
    cout << max << endl << index+1;
    
    return 0;
}