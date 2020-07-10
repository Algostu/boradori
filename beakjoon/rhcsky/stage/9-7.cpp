#include <iostream>
using namespace std;

int main()
{
    int test,a,b;
    cin >> test;
    while (test--)
    {
        cin >> a >> b;
        int* ho = new int[b+1];
        for (int i = 1; i <= b; i++)
        {
            ho[i] = i;
        }
            
        for (int i = 0; i < a; i++)
        {
            for (int j = 2; j <= b; j++)
            {             
                ho[j] += ho[j-1];
            }
        }
        cout << ho[b] << endl;
    }
    return 0;
}