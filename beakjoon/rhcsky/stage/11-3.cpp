#include <iostream>
using namespace std;

void PrintStar(int x, int y){
    while(x != 0){
        if (x%3==1 && y%3==1)
        {
            cout << " ";
            return;
        }
         x/=3;
         y/=3;
    }
    cout << "*";
}

int main()
{
    int input;
    cin >> input;
    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < input; j++)
        {
            PrintStar(i,j);
        }
        cout << endl;
    }
    
    return 0;
}