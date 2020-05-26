#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N, age;
    string name;
    vector<pair<int, string>> v;
    scanf("%d", &N);
    while (N--)
    {
        cin >> age >> name;
        v.push_back(make_pair(age, name));
    }
    stable_sort(v.begin(), v.end(), [](const pair<int, string> &p1, const pair<int, string> &p2) { return p1.first < p2.first; });

    for (auto &&i : v)
    {
        printf("%d %s\n",i.first,i.second.c_str());
    }
    
    return 0;
}