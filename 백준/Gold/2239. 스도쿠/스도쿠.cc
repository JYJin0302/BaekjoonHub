#include <bits/stdc++.h>
using namespace std;



int grid[9][9];
vector<int> row;
vector<int> col;

bool ok(int r, int c, int base) {
    for (int i = 0; i < 9; i++) {
        if (i != c && grid[r][i] == base) return false;
        if (i != r && grid[i][c] == base) return false;
    }
    for (int i = (r / 3) * 3; i < (r / 3)*3 + 3; i++) for (int j = (c / 3) * 3; j < (c / 3) * 3 + 3; j++) {
        if (!(i == r && j == c) && grid[i][j] == base) return false;
    }
    return true;
}

int tot;
bool found;
void solve(int cnt) {
    if (cnt == tot) {
        found = true; return;
    }

    for (int i = 1; i <= 9; i++) {
        if (!ok(row[cnt], col[cnt], i)) continue;
        grid[row[cnt]][col[cnt]] = i;
        solve(cnt + 1);
        if (found) return;
        grid[row[cnt]][col[cnt]] = 0;
    }
}


int main() {
    for (int i = 0; i < 9; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 9; j++) {
            grid[i][j] = s[j] - '0';
            if (grid[i][j] == 0) {
                row.push_back(i);
                col.push_back(j);
            }
        }
    }

    found = false;

    tot = row.size();
    solve(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) cout << grid[i][j];
        cout << '\n';
    }
}