#include <iostream>
using namespace std;

bool is_prime(int);

int main()
{
    int a,b,first = 0, sum=0;
    cin >> a >> b;
    for(int i = a; i<=b; i++){
        if(is_prime(i)){
            sum +=i;
            if(first==0) first = i;
        }
    }

    if(sum==0) cout << -1;
    else{
        cout << sum << endl << first;
    }
    
    return 0;
}

bool is_prime(int input)
{
    if (input < 2)
        return false;
    else
    {
        for (int i = 2; i <= input / 2; i++)
        {
            if (input % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}