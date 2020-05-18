#include <iostream>
using namespace std;

int main()
{
    int n,score=0, cnt=0;;
    string result;
    cin >> n;
    while(n--)
    {
        cin >> result;
        for (int j = 0; j < result.length(); j++)
        {
            if(result[j]=='O') {
                cnt++;
                score+=cnt;
            }
            else cnt=0;
        }
        cout << score << endl;
        score = 0;
        cnt = 0;
    }
    
    return 0;
}