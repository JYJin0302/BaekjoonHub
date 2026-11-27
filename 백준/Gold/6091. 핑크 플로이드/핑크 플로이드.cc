#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 15001));
    vector<bool> check(n + 1);

    vector<set<int>> adj(n + 1);

    for (int i = 1; i <= n - 1; i++) for (int j = i + 1; j <= n; j++) {
        if (i == j) continue;
        cin >> grid[i][j];
        grid[j][i] = grid[i][j];
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j == i || check[j]) continue;
            bool ok = true;
            for (int k = 1; k <= n; k++) {
                if (k == j || k == i) continue;
                if (grid[i][k] + grid[k][j] == grid[i][j]) {
                    ok = false;
                    break;
                }
            }
            
            if (ok) {
                adj[i].insert(j);
                adj[j].insert(i);
            }
           
        } 
        check[i] = 1;
    }

    set<int> ::iterator it;
    for (int i = 1; i <= n; i++) {

        cout << adj[i].size() << ' ';
        for (it = adj[i].begin(); it != adj[i].end(); it++) {
            cout << *it << ' ';
        }
        cout << '\n';
    }

}