#include <iostream>
 
int n, m;
int lists[9];
bool check[9] = { 0, };
 
 
void dfs(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            std::cout << lists[i] << " ";
        }
        std::cout << "\n";
        return;
    }
 
    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            check[i] = true;
            lists[cnt] = i;
            dfs(cnt + 1);
            check[i] = false;
        }
    }
}
 
int main() {
    std::cin >> n >> m;
 
    dfs(0);
 
    return 0;
}

