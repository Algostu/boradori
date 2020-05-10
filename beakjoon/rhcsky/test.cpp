#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
	string inp;
	getline(cin,inp);
	stringstream ss(inp);

	string str;
	while(ss>>str) {
		cout<<str<<' ';
	}
	return 0;
}