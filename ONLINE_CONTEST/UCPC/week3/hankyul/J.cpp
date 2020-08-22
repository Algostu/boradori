#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

void solve(int test_num=0) {
	int N,M,K,Q, ans = 0;
	int in_r, in_c, in_g;
	char in_str[4];

	std::cin >> N >> M >> K >> Q;
	getchar();

	vector <pair<int, char>> row_room[M], col_room[N];

	for (size_t i = 0; i < K; i++) {
		scanf("%d %d %c\n", &in_r, &in_c, &in_g);
		getchar();
		row_room[in_r].push_back({in_c, in_g});
		col_room[in_c].push_back({in_r, in_g});
	}

	for (size_t i = 0; i < Q; i++) {
		scanf("%s", in_str);
		std::cout << in_str << '\n';
	}

	printf("%d \n", ans);
}

int main(int argc, char const *argv[]) {
	solve();
	return 0;
}
