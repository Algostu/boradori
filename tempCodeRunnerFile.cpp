#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, -1, 1, 0, 0};
int R, C, M;
int r, c, s, d, z;
int sol;
int map[102][102] = { 0 };

struct Shark {
	int r, c, s, d, z;
	bool alive = true;
    Shark(int _r, int _c, int  _s, int  _d, int  _z) :r(_r), c(_c), s(_s), d(_d), z(_z) {
        if (d < 3) { s %= (2 * (R - 1)); }
		else { s %= (2 * (C - 1)); }
	}
};

vector<Shark> v;

pair<int, int> change(int pos, int dir, int maxlen, int xy) {
	while (pos < 1 || pos > maxlen) {
		if (pos < 1) {
			pos = pos * (-1) + 2;
			dir = (xy == 0) ? 3 : 2;
		}
		if (pos > maxlen) {
			pos = 2 * maxlen - pos;
			dir = (xy == 0) ? 4 : 1;
		}
	}
	return { pos, dir };
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &R, &C, &M); //Y, X, 상어수

	sol = 0;
	for (int x = 1; x <= C; ++x) {
		for (int y = 1; y <= R; ++y) {
			map[y][x] = -1;
		}
	}
	
	for (int m = 0; m < M; m++) {
		scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
		v.push_back(Shark(r, c, s, d, z));
		map[r][c] = m;
	}

	for (int x = 1; x <= C; ++x) {
		//상어 잡기
		for (int y = 1; y <= R; ++y) {
			if (map[y][x] != -1) {
				v[map[y][x]].alive = false;
				sol += v[map[y][x]].z;
				cout << v[map[y][x]].z << endl;
				break;
			}
		}

		for (int yy = 1; yy <= R; ++yy) {
			for (int xx = 1; xx <= C; ++xx) {
				map[yy][xx] = -1;
			}
		}
		int nx, ny;
		for (int m = 0; m < M; m++) {
			if (v[m].alive) {
				nx = v[m].c + dx[v[m].d] * v[m].s;
				ny = v[m].r + dy[v[m].d] * v[m].s;
				
				if (nx<1 || nx>C) {
					pair<int, int> tmp = change(nx, v[m].d, C, 0);
					v[m].c = tmp.first;
					nx = v[m].c;
					
					v[m].d = tmp.second;
				}
				if (ny<1 || ny>R) {
					pair<int, int> tmp = change(ny, v[m].d, R, 1);
					v[m].r = tmp.first;
					ny = v[m].r;
					
					v[m].d = tmp.second;
				}
				v[m].c = nx; v[m].r = ny;
				
				if (map[ny][nx] == -1) {
					map[ny][nx] = m;
				}
				else {
					if (v[map[ny][nx]].z < v[m].z) {
						v[map[ny][nx]].alive = false;
						v[m].c = nx;
						v[m].r = ny;
						map[ny][nx] = m;
					}
					else {
						v[m].alive = false;
						//v[m].z = 0;
					}
				}
			}
		}
	}
	printf("%d\n", sol);

	return 0;
}