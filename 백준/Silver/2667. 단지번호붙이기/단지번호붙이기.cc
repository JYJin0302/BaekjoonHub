#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int grid[25][25];
int check[25][25];
int step[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool ingrid(int r, int c) {
    return (r >= 0 && r < n) && (c >= 0 && c < n);
}


void dps(int r, int c) {
    check[r][c] = 1;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int newr = r + step[i][0];
        int newc = c + step[i][1];
        if (ingrid(newr, newc) && grid[newr][newc] && !check[newr][newc]) {
            dps(newr, newc);
        }
    }


}




int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') grid[i][j] = 1;
        }
    }
    vector<int> ans;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (!check[i][j] && grid[i][j]) {
            cnt = 0;
            dps(i, j);
            ans.push_back(cnt);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << '\n';
}  
