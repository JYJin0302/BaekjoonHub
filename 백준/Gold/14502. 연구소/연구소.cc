#include <bits/stdc++.h>
using namespace std;

int n, m, ans, tempA, r, c, nr, nc;
vector<vector<int>> grid;
vector<vector<int>> tempM;
vector<vector<int>> check;
int step[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
vector<pair<int, int>> safe;
queue<pair<int, int>> virus;
queue<pair<int, int>> tempV;

bool inmap(int r, int c) {
    return (r >= 0 && r < n) && (c >= 0 && c < m);
}


void bps() {
    while (!tempV.empty()) {
        r = tempV.front().first;
        c = tempV.front().second;
        tempV.pop();
        for (int i = 0; i < 4; i++) {
            nr = r + step[i][0];
            nc = c + step[i][1];
            if (inmap(nr, nc) && !check[nr][nc] && tempM[nr][nc] == 0) {
                check[nr][nc] = 1;
                tempM[nr][nc] = 2;
                tempV.push(make_pair(nr, nc));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    grid = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) virus.push(make_pair(i, j));
            else if (grid[i][j] == 0) safe.push_back(make_pair(i, j));
        }
    }
    ans = 0;
    for (int i = 0; i < safe.size(); i++) {
        for (int j = i + 1; j < safe.size(); j++) {
            for (int k = j + 1; k < safe.size(); k++) {
                check = vector<vector<int>>(n, vector<int>(m));
                tempM = grid;
                tempM[safe[i].first][safe[i].second] = 1;
                tempM[safe[j].first][safe[j].second] = 1;
                tempM[safe[k].first][safe[k].second] = 1;
                
                tempV = virus;
                bps();
                tempA = 0;
                for (int x = 0; x < n; x++) for (int y = 0; y < m; y++) {
                    if (tempM[x][y] == 0) tempA++;
                }
                ans = max(ans, tempA);
            }
        }
    }

    cout << ans;
}