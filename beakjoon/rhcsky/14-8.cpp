#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N;
    string input;
    vector<pair<int,string>> v;
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++)
    {
        getline(cin,input);
        v.push_back(make_pair(input.size(),input));
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    cout << v[1].second << endl;
    for (auto &&i : v)
    {
        printf("%s\n",i.second.c_str());
    }
    
    return 0;
}
