#include <iostream>
using namespace std;

int main(){
    int n, prev, temp, cnt=0;
    string input;
    cin >> n;
    cin.ignore();

    while (n--)
    {
        cnt++;
        int alphabet[26] = {0,};
        getline(cin,input);
        prev = input[0] - 'a';
        for (auto &&word : input)
        {   
            temp = word - 'a';
            alphabet[temp]++;
            if(alphabet[temp]>1 && prev != temp){
                cnt--;
                break;
            }
            prev = word-'a';
        }
    }
    cout << cnt;
    return 0;
}