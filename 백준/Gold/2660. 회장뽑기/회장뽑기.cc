#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n;
    int INF = n-1;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        if (i == j) grid[i][j] = 0;
        else grid[i][j] = INF;
    }

    cin >> a >> b;
    while (!(a == -1 && b == -1)) {
        grid[a][b] = 1;
        grid[b][a] = 1;
        cin >> a >> b;
    }

    for (int t = 1; t <= n; t++) {
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
            grid[i][j] = min(grid[i][j], grid[i][t] + grid[t][j]);
        }
    }


    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        int temp = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            temp = max(temp, grid[i][j]);
        }
        ans[i] = temp;
    }

    int score = *min_element(ans.begin()+1, ans.end());
    int cnt = count(ans.begin()+1, ans.end(), score);
    cout << score << ' ' << cnt << '\n';
    for (int i = 1; i <= n; i++) {
        if (ans[i] == score) cout << i << ' ';
    }
}