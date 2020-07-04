#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int N;
    string input;
    vector<string> v;
    vector<string> split[101];
    cin >> N;
    cin.ignore();

    for (int i = 0; i < N; i++)
    {
        getline(cin,input);
        
        v.push_back(input);
    }

    int i=0;
    for (auto &&as : v)
    {
        istringstream ss(as);
        string stringBuffer;

        while (getline(ss, stringBuffer, ' '))
        {
            split[i].push_back(stringBuffer);
        }
        i++;
    }

    for (int i = 0; i < N; i++)
    {
        split[i][0] = "god";
    }

    for (int i = 0; i < N; i++)
    {
        for (auto &&i : split[i])
        {
            cout << i;
        }
        cout << endl;
    }
    
    return 0;
}