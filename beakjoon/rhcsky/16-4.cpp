#include <iostream>
using namespace std;

int main(){
    int test, input;
    long long modi_fibo[4];
    cin >> test;
    while (test--)
    {
        cin >> input;
        input--;
        modi_fibo[0] = 1;
        modi_fibo[1] = 1;
        modi_fibo[2] = 1;

        for (int i = 0; i < input/3; i++)
        {
            modi_fibo[0] = modi_fibo[3] = modi_fibo[0]+modi_fibo[1];
            modi_fibo[1] = modi_fibo[1] + modi_fibo[2];
            modi_fibo[2] = modi_fibo[2] + modi_fibo[3];
        }

        cout << modi_fibo[input%3] << endl;
    }
    return 0;
}