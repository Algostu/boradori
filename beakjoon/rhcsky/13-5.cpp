#include <iostream>
#include <string>
using namespace std;

int main(){
    int input, cnt=0, first=665;
    cin >> input;
    string title;
    while (first++)
    {
        title = to_string(first);
        
        if(title.find("666") != string::npos)
            cnt++;          

        if(cnt==input){
            cout << first;
            return 0;
        }
    }
    return 0;
}