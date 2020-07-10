#include <string>
#include <vector>

using namespace std;
string myprint(string str);


int main(){
    int n;
    string input;
    vector<string> ans;
    cin >> n;
    cin.ignore();
    do
    {
        getline(cin,input);
        ans.push_back(myprint(input));
    } while (--n);
    
    for (auto &&a : ans)
    {
        cout << a << endl;
    }
    
    return 0;
}

string myprint(string str){

    int times = str[0] - '0';
    string ans;
    for (int i = 2; i < str.length(); i++)
    {
        for (int j = 0; j < times; j++)
        {
            ans.push_back(str[i]);
        }
    }
    return ans;
}