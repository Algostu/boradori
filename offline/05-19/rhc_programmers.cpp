/* Programmers 2018 Summer/Winter 쿠키 구입
https://programmers.co.kr/learn/courses/30/lessons/49995
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> cookie) {

    int pointer, left_pointer, max = 0;
    int left,right;
    
    for (int i = 1; i < cookie.size(); i++)
    {
        pointer = i;
        left_pointer = i-1;
        left = cookie[left_pointer];
        right = cookie[pointer];
        while(left_pointer >= 0 && pointer < cookie.size()){
            // printf("i : %d || Left : %d || Right : %d\n",i, left,right);
            if(left > right) {
                pointer++;
                right += cookie[pointer];
            }
            else if(left < right) {
                left_pointer--;
                left += cookie[left_pointer];
            }
            else{
                if(max<right) max = right;
                pointer++;
                left_pointer--;
                right += cookie[pointer];
                left += cookie[left_pointer];
            }
        }
    }
    
    if(max==0) return 0;
    else return max;
}


int main(){
    vector<int> cookie = {1,1,1,1,1,1,1,1};

    cout << solution(cookie);

    return 0;
}