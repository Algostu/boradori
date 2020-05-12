#include <iostream>
#include <string>

using namespace std;

int main(void){
  int ans = 0;
  string input_str;
  char * tok;

  getline(cin, input_str);

  tok = strtok(input_str, " ");

  cout << tok;

  return 0;
}
