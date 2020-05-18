#include <iostream>
#include <algorithm>
using namespace std;
//ASCHI a = 97 z=122 alphabet = 26
#define ALPHABET 26
char numChar(string);

int main()
{
    string input;
    getline(cin,input);
    cout << numChar(input) << endl;

    return 0;
}

char numChar(string str) 
{   
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    int alphabet[ALPHABET] = {0,}; 
    int max = 0, index=0;
    for (int i=0; i<str.length(); i++) {
        alphabet[str[i]-'A']++;
        if(max < alphabet[str[i]-'A']){
            max = alphabet[str[i]-'A'];
            index = str[i]-'A';
        }
    }
    for (int j = 0; j < 26; j++)
    {   
        if(j!=index){
            if(max==alphabet[j]){
                return '?';
            }
        }
    }

    return (char)(index + 'A') ;
} 