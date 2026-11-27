#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

char grid[10][10];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool inGrid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int sz = 0;
map<pair<int, int>, int> dp;

int getVal(vector<int>& x) {
    int res = 0;
    for (auto i : x) {
        res = res * 64 + i;
    }
    return res;
}



vector<int> getV(int val) {
    vector<int> res;
    for (int i = 0; i < sz; i++) {
        res.push_back(val % 64);
        val /= 64;
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(grid, ' ', sizeof(grid));

    string s;
    int i = 0;
    while (getline(cin, s)) {
        for (int j = 0; j < s.size(); j++) grid[i][j] = s[j];
        i++;
    }

    vector<int> boxes, storage;
    int player = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c = grid[i][j];
            if (c == '@' || c == '+') player = i * 8 + j;
            if (c == '.' || c == '*' || c == '+') storage.push_back(i * 8 + j);
            if (c == '$' || c == '*') boxes.push_back(i * 8 + j);
            if (c != '#') grid[i][j] = ' ';
        }
    }

    sz = boxes.size();

    int bVal = getVal(boxes);
    dp[mp(player, bVal)] = 1;
    deque<pair<int, int>> q;
    q.push_front(mp(player, bVal));
    while (!q.empty()) {

        int pPos;
        tie(pPos, bVal) = q.front();
        q.pop_front();

        vector<int> bosV = getV(bVal);

        if (bosV == storage) {
            cout << dp[mp(pPos, bVal)] - 1;
            return 0;
        }

        int currVal = dp[mp(pPos, bVal)];

        int px, py;
        px = pPos / 8;
        py = pPos % 8;
        for (int i = 0; i < 4; i++) {

            int nx = px + dx[i];
            int ny = py + dy[i];

            if (!inGrid(nx, ny) || grid[nx][ny] == '#') continue;

            int nVal = nx * 8 + ny;

            if (find(bosV.begin(), bosV.end(), nVal) == bosV.end()) {
                if (dp[mp(nVal, bVal)] == 0) {
                    dp[mp(nVal, bVal)] = currVal;
                    q.push_front(mp(nVal, bVal));
                }
            }
            else {
                // box here
                int nnx = nx + dx[i];
                int nny = ny + dy[i];

                int nnVal = nnx * 8 + nny;
                if (inGrid(nnx, nny) && grid[nnx][nny] != '#' && find(bosV.begin(), bosV.end(), nnVal) == bosV.end()){
                    // can move this box

                    vector<int> newB = bosV;
                    newB.erase(find(newB.begin(), newB.end(), nVal));
                    newB.push_back(nnVal);
                    sort(newB.begin(), newB.end());

                    int nxtV = getVal(newB);

                    if (dp[mp(nVal, nxtV)] == 0) {
                        dp[mp(nVal, nxtV)] = currVal + 1;
                        q.push_back(mp(nVal, nxtV));
                    }
                }

            }

        }
    }


}