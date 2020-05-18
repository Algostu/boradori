#include <iostream>
#include <vector>
using namespace std;

int main(){

    string input;
    int cnt=0, num, temp;
    getline(cin,input);

    vector<string> croatia = {"c=","c-","z=","d-","lj","nj","s=","dz="};
    num = croatia.size()-1;

    while(num>=0){
        temp = input.find(croatia[num]);
        if (temp < input.length()){
            cnt++;
            input.erase(temp,croatia[num].length());
            input.insert(temp,",");
        }
        else num--;
    }

    temp = input.find(",");
    while(temp < input.length()){
        input.erase(temp,1);
        temp = input.find(",");
    }

    cnt += input.length();
    cout << cnt;
    return 0;
}