#include <cstdio>
using namespace std;

bool grid[14][14] = { false, };
int ans = 0;
int N;

bool isValid(int i, int cnt) {
    int x, y;
    for (x = 0; x < cnt; x++) {
        if (grid[i][x]) return false;
    }

    for (x = cnt - 1, y = i - 1; y >= 0; x--, y--) {
        if (grid[y][x]) return false;
    }

    for (x = cnt - 1, y = i + 1; y < N; x--, y++) {
        if (grid[y][x]) return false;
    }
    
    return true;

}

void dfs(int cnt) {
    
    int i;

    // basecase
    if (cnt == N) {
        ans++;
        return;
    }

    for (i = 0; i < N; i++) {
        if (!grid[i][cnt] && isValid(i, cnt)) {
            // constraint satisfied
            grid[i][cnt] = true;
            dfs(cnt+1);
            grid[i][cnt] = false;
        }
    }

}

int main() {

    scanf("%d", &N);

    dfs(0);
    printf("%d\n", ans);

    return 0;
}