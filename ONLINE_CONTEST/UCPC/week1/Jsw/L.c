#include <iostream>
using namespace std;

int main()
{
	int n, k, p, w;
	cin >> n >> k >> p >> w;
	if(p%w == 0)
        	cout << p / w;
    	else
        	cout << (int)p / w + 1;
	return 0;
}
