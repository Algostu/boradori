#include <iostream>
using namespace std;

int main()
{
    unsigned int test, start, end, i=1;
    cin >> test;
    while (test--)
    {
        cin >> start >> end;
        for (i = 1; ; i++)
        {
            if (i*i>=end-start){
                if (end-start>i*i-i) cout << 2*i-1 << endl;
                else cout << 2*i-2 << endl;
                break;
            }          
        }
    }
    return 0;
}