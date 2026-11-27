#include <bits/stdc++.h>
using namespace std;
int t, w, h, r, c, nr, nc;
char grid[1000][1000];
queue<pair<int, int>> fire;
queue<pair<int, int>> man;
queue<pair<int, int>> temp;
bool escape;
int sec = 0;
int step[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool ingrid(int r, int c) {
    return (r >= 0 && r < h) && (c >= 0 && c < w);
}

bool endofgrid(int r, int c) {
    return r == 0 || r == h - 1 || c == 0 || c == w - 1;
}

void solve() {
    sec++;
    while (!fire.empty()) {
        r = fire.front().first;
        c = fire.front().second;
        fire.pop();
        for (int i = 0; i < 4; i++) {
            nr = r + step[i][0];
            nc = c + step[i][1];
            if (ingrid(nr, nc) && (grid[nr][nc] == '@' || grid[nr][nc] == '.')) {
                grid[nr][nc] = '*';
                temp.push(make_pair(nr, nc));
            }
        }
    }
    swap(fire, temp);

    while (!man.empty()) {
        r = man.front().first;
        c = man.front().second;
        man.pop();
        if (endofgrid(r, c)) {
            escape = true;
            return;
        }
        for (int i = 0; i < 4; i++) {
            nr = r + step[i][0];
            nc = c + step[i][1];
            if (ingrid(nr, nc) && grid[nr][nc] == '.') {
                grid[nr][nc] = '@';
                temp.push(make_pair(nr, nc));
            }
        }
    }

    swap(man, temp);
    if (man.empty()) return;
    solve();
}




int main() {
    cin >> t;
    while (t--) {
        cin >> w >> h;
        fire = {};
        man = {};
        escape = false;
        for (int i = 0; i < h; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < w; j++) {
                grid[i][j] = s[j];
                if (grid[i][j] == '*') fire.push(make_pair(i, j));
                if (grid[i][j] == '@') man.push(make_pair(i, j));
            }
        }
        sec = 0;

        solve();

        if (escape) cout << sec;
        else cout << "IMPOSSIBLE";
        cout << '\n';
    }
}