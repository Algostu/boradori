#include <bits/stdc++.h>

using namespace std;

void Combination(vector<char> arr, vector<char> comb, int r, int index, int depth)
{
    if (r == 0)
    {
        for(int i = 0; i < comb.size(); i++)
            cout << comb[i] << " ";
        cout << endl;
    }
    else if (depth + r > arr.size())  // depth == n
    {
        return;
    }
    else
    {
        comb[index] = arr[depth];
        Combination(arr, comb, r - 1, index + 1, depth + 1);
        
        Combination(arr, comb, r, index, depth + 1);
    }
}

int main()
{
    vector<char> vec = {'a', 'b', 'c', 'd', 'e'};  // n = 5
    
    int r = 3;
    vector<char> comb(r);
    
    Combination(vec, comb, r, 0, 0);  // {'a', 'b', 'c', 'd', 'e'}의 '5C3' 구하기 

    return 0;
}
