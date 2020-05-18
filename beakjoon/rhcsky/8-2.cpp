#include <iostream>
using namespace std;

int main()
{
    int n;
    string nums;
    cin >> n;
    cin >> nums;
    n=0;
    for (auto &&num : nums)
    {   
        cout << "D";
        n+=num-'0';
    }
    cout << n;
    
    return 0;
}