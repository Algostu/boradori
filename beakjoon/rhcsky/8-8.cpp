#include <iostream>
using namespace std;
//ASCHI A = 65 Z = 90
#define ALPHABET 26
int main(){
    int alpha2num[ALPHABET] = {0,};
    int interval[] = {3,3,3,3,3,4,3,4};
    int sum=0, second = 3, i = 0, j = 0;
    string input;
    getline(cin,input);

    for (auto &&word : input)
    {
        alpha2num[word-'A']++;
    }

    while (i<26)
    {   
        if(interval[j] == 3){
            sum += (alpha2num[i] + alpha2num[i+1] + alpha2num[i+2])*second;
            second++;
            i += interval[j];
        }
        else{
            sum +=(alpha2num[i] + alpha2num[i+1] + alpha2num[i+2] + alpha2num[i+3])*second;
            second++;
            i += interval[j];
        }
        j++;
    }
    cout << sum;
    return 0;    
}