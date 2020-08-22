/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define LONG_MAX 2147483647

void get_input(vector<int> & vec, int N){
  for (size_t i = 0; i < N; i++) {
    int temp;

    scanf("%d", &temp);
    vec.push_back(temp);
  }
  sort(vec.begin(), vec.end());
}



void solve(long long & Answer){
  int ans = 0;
  int N, K;
  vector<int> menu_a, menu_b;
  scanf("%d %d", &N, &K);

  // get menu and sort
  get_input(menu_a, N); get_input(menu_b, N);

  // get base max
  long long max = 0;

  for (size_t i = 0; i < K; i++) {
    if ( max < menu_a[i] + menu_b[K-i-1] ) max = menu_a[i] + menu_b[K-i-1];
  }

  Answer = max;
}

int main(int argc, char** argv)
//int main(void)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		long long Answer = 0;

    solve(Answer);

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
