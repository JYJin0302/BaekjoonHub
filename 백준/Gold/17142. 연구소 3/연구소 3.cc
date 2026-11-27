#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int n, m, r, c, nr, nc, blanks, blankcnt;
int basegrid[50][50];
int grid[50][50];
int check[50][50];
int ans, tempans;
int step[4][2] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };

queue<pair<int, int>> q;
queue<pair<int, int>> temp;

vector<pair<int, int>> virus;
vector<pair<int, int>> selectedvirus;

void clearqueue(queue<pair<int, int>>& s) {
    queue<pair<int, int>> asdf;
    swap(s, asdf);
}

bool ingrid(int r, int c) {
    return (r >= 0 && r < n&& c >= 0 && c < n);
}


void bfs() {
    while (!q.empty()) {
        tie(r, c) = q.front();
        check[r][c] = 1;
        q.pop();
        for (int i = 0; i < 4; i++) {
            nr = r + step[i][0];
            nc = c + step[i][1];
            if (ingrid(nr, nc) && (grid[nr][nc] == 0 || grid[nr][nc] == 2)) {
                if (check[nr][nc]) continue;
                
                temp.push({ nr, nc });
                if (grid[nr][nc] == 0) blankcnt++;
                grid[nr][nc] = 2;
                check[nr][nc] = 1;
            }
        }
        if (blankcnt == blanks) {
            tempans++; return;
        }
    }
    swap(q, temp);

    if (q.empty() || blankcnt == blanks) return;
    tempans++;

    bfs();
}

void execute() {
    blankcnt = 0;
    clearqueue(q);
    clearqueue(temp);
    for (auto i : selectedvirus) {
        q.push(i);
    }
    tempans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = basegrid[i][j];
            check[i][j] = 0;
        }
    }
    bfs();
    if (blankcnt != blanks) return;
    ans = min(tempans, ans);
    return;
}

void selectvirus(int f = 0, int cnt = 0) {
    if (cnt == m) {
        execute();
        return;
    }
    for (int i = f; i < virus.size(); i++) {
        selectedvirus[cnt] = virus[i];
        selectvirus(i + 1, cnt + 1);
    }
}

int main() {

    cin >> n >> m;
    blanks = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> basegrid[i][j];
            if (basegrid[i][j] == 2) virus.push_back({ i, j });
            else if (basegrid[i][j] == 0) blanks++;
        }
    }

    if (blanks == 0) {
        cout << 0 << '\n';
        return 0;
    }
    selectedvirus = vector<pair<int, int>>(m);
    ans = INF;
    selectvirus();

    if (ans == INF) cout << -1;
    else cout << ans;
}