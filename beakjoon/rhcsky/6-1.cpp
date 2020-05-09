#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;

    cin >> n;
    int *nums = new int[n];

    for(int i=0;i<n;i++) cin >> nums[i];

    sort(nums,nums+n);

    cout << nums[0] << " " << nums[n-1];
    
    return 0;
}