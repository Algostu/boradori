#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nx, ny, l, cnt;
    bool visit[10][10] = {
        false,
    };

    while (true) {
        if (nx < 0 || ny < 0 || nx >= l || ny >= l || visit[nx][ny]) continue;
        visit[nx][ny] = true;
        q.push({cnt + 1, nx, ny});

        // if (nx >= 0 && ny >= 0 && nx < l && ny < l && visit[nx][ny] == false) {
        //     visit[nx][ny] = true;
        //     q.push({cnt + 1, nx, ny});
        // }
    }

    return 0;
}