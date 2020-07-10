#include <iostream>
using namespace std;
//ASCHI a = 97 z=122
int main()
{
    int array[26];
    int res[26];
    fill_n(res,sizeof(res)/sizeof(int),-1);
    for (int i = 0; i < 26; i++) array[i] = i+97;
    
    string words;
    cin >> words;

    for (int j = 0; j<words.length(); j++)
    {
        for (int i = 0; i < 26; i++)
        {
            if((int)words[j] == array[i]) {
                if(res[i] == -1) res[i] = j;
            }
        }
    }
    
    for (auto &&a : res)
    {
        cout << a << " ";
    }
    
    return 0;
}