#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int num,cnt;
    string input;
    cin >> num;
    cin.ignore();
    getline(cin,input);
    cnt = num;
    vector<int> numbers;
    istringstream f(input);
    
    while(getline(f,input,' ')){
        numbers.push_back(stoi(input));
    }

    for(auto &&input : numbers){
        if (input<2) cnt--;
        else{
            for (int i = 2; i <= input/2; i++)
            {
                if(input%i == 0){
                    cnt--;
                    break;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}