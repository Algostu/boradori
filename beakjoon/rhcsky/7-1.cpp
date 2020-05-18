#include <iostream>

using namespace std;

int main()
{
    int test,n,sum,input,cnt;
    float aver;
    cin >> test;
    while (test--)
    {   
        sum = cnt = 0;
        cin >> n;
        int *score = new int[n];
    
        for (int i = 0; i < n; i++)
        {   
            cin >> input;
            score[i] = input;
            sum += input;
        }
        aver = sum/n;
        for (int i = 0; i < n; i++)
        {
            if (score[i] > aver) cnt++;
        }
        cout << fixed;
        cout.precision(3);
        cout << (float)cnt/n*100 << "%" << endl;        
        printf("%.3lf%\n",cnt/n*100);
    }
    
    return 0;
}