#include <iostream>

int n, m;
int lists[9];
bool check[9] = { 0, };
 
 
void dfs(int cnt) {
    int k = 0;
    if (cnt == m) {
        for (k = 0; k < m - 1; k++)
            if (lists[k] > lists[k + 1]) break;
        
        if (k == m - 1)
        {
            for (int i = 0; i < m; i++) {
                std::cout << lists[i] << " ";
            }
            std::cout << "\n";
        }
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
