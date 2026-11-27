#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int n;
int dx[] = { -1, 0, 1, 0, -1,-1, 1, 1 };
int dy[] = { 0, 1, 0, -1, -1, 1, -1, 1 };
int dNx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dNy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < n;
}

char grid[55][55];
bool isShine[55][55];
bool isFreedom[55][55];
int birdCnt[55][55];
bool vs[55][55];

map<string, int> cnt;

void solve() {

    cin >> n;
    cin.ignore();

    string s;
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (int j = 0; j < n; j++) grid[i][j] = s[j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == ' ') {
                cnt["space"]++;
            }
            else if (grid[i][j] == '*') {
                cnt["sun"]++;
            }
            else if (grid[i][j] == 'v') {
                cnt["bird"]++;
            }
            else if (grid[i][j] == 'D') {
                cnt["drake"]++;
            }
            else if (grid[i][j] == '^') {
                cnt["house"]++;
            }
            else if (grid[i][j] == '!') {
                cnt["chu"]++;
            }
            else if (grid[i][j] == '/') {
                cnt["left"]++;
            }
            else if (grid[i][j] == '\\') {
                cnt["right"]++;
            }
            else if (grid[i][j] == 'G') {
                cnt["grill"]++;
            }
        }
    }

    vector<pair<int, int>> peak;

    int ans = 0;

    map<string, bool> uniq;
    for (int i = 0; i < n-2; i++) {
        for (int j = 0; j < n-2; j++) {
            string ts;
            for (int f = 0; f < 3; f++) {
                for (int v = 0; v < 3; v++) {
                    ts += grid[i + f][j + v];
                }
            }
            if (!uniq[ts]) {
                ans++;
            }
            uniq[ts] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (grid[i][j] == '*') {
                for (int f = 0; f < 8; f++) {
                    int ni = i + dx[f];
                    int nj = j + dy[f];
                    while (inGrid(ni, nj) && grid[ni][nj] == ' ') {
                        ni += dx[f];
                        nj += dy[f];
                    }
                    if (inGrid(ni, nj) && grid[ni][nj] != '*') isShine[ni][nj] = 1;
                }
            }

            if (grid[i][j] == 'v' || grid[i][j] == 'D') {
                birdCnt[i][j]++;
                if (j) birdCnt[i][j] += birdCnt[i][j - 1];

                bool ok = 0;
                for (int f = 0; f < 8; f++) {
                    int ni = i + dNx[f];
                    int nj = j + dNy[f];
                    if (inGrid(ni, nj) && grid[ni][nj] == '!') ok = 1;
                }
                if (ok) {
                    ans += 200;
                }
            }
            
            if (grid[i][j] == '^') {
                // house
                int ti = i - 1;
                while (ti >= 0 && grid[ti][j] == ' ') {
                    ans += 15;
                    ti--;
                }
            }

            if (grid[i][j] == '\\' && j && grid[i][j-1] == '/') {
                // peak
                peak.push_back(mp(i, j));
            }

            if (grid[i][j] == 'D') {
                bool ok = 0;
                for (int f = 0; f < 4; f++) {
                    int ni = i + dx[f];
                    int nj = j + dy[f];
                    if (inGrid(ni, nj) && grid[ni][nj] == 'G') {
                        ok = 1;
                    }
                }
                if (ok) {
                    ans += 500;
                }
            }


            if (grid[i][j] == 'G') {
                bool ok = 0;
                for (int f = 0; f < 4; f++) {
                    int ni = i + dx[f];
                    int nj = j + dy[f];
                    if (inGrid(ni, nj) && grid[ni][nj] == 'D') {
                        ok = 1;
                    }
                }
                if (ok) {
                    ans += 50;
                }
            }
        }
    }
    
    ans += min(cnt["house"], cnt["grill"]) * 3;
    ans += cnt["space"];
    ans += cnt["chu"] * cnt["bird"] * cnt["drake"];

    int mFre = n * n;
    for (auto f : { "sun", "bird", "drake", "house", "chu", "left", "right", "grill" }) {
        if (cnt[f] > 0) mFre = min(mFre, cnt[f]);
    }
    for (auto f : { "sun", "bird", "drake", "house", "chu", "left", "right", "grill" }) {
        if (cnt[f] == mFre) {
            ans += cnt[f] * 10;
        }
    }

    for (auto& i : peak) {
        int mDist = 0;
        for (auto& j : peak) {
            mDist = max(mDist, abs(i.first - j.first) + abs(i.second - j.second));
        }
        ans += mDist * 50;
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        isFreedom[i][0] = isFreedom[i][n - 1] = isFreedom[0][i] = isFreedom[n - 1][i] = 1;
        vs[i][0] = vs[i][n - 1] = vs[0][i] = vs[n - 1][i] = 1;
        if (grid[i][0] == ' ') q.push(mp(i, 0));
        if (grid[i][n - 1] == ' ') q.push(mp(i, n - 1));
        if (grid[0][i] == ' ') q.push(mp(0, i));
        if (grid[n - 1][i] == ' ') q.push(mp(n - 1, i));
    }
    while (!q.empty()) {
        int a, b;
        tie(a, b) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];
            if (inGrid(na, nb) && !vs[na][nb]){
                vs[na][nb] = isFreedom[na][nb] = 1;
                if (grid[na][nb] == ' ') q.push(mp(na, nb));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != ' ') {
                if (isShine[i][j]) {
                    ans += 100;
                }
                if (isFreedom[i][j]) {
                    ans += 7;
                }
            }
            else {

                for (int f = 0; f < 4; f++) {
                    int ni = i + dx[f];
                    int nj = j + dy[f];

                    if (inGrid(ni, nj) && (grid[ni][nj] == 'v' || grid[ni][nj] == 'D' || grid[ni][nj] == '!')) ans += 15;
                }
            }
        }
    }

    memset(vs, 0, sizeof(vs));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'v' || grid[i][j] == 'D') {
                if (vs[i][j]) continue;

                int len = 0;
                int wid = 0;

                q.push(mp(i, j));
                vs[i][j] = 1;

                while (!q.empty()) {

                    int a, b;
                    tie(a, b) = q.front();
                    q.pop();

                    len += 4;
                    wid = max(wid, birdCnt[a][b]);

                    for (int f = 0; f < 4; f++) {
                        int na = a + dx[f];
                        int nb = b + dy[f];

                        if (inGrid(na, nb) && (grid[na][nb] == 'v' || grid[na][nb] == 'D')) {
                            len--;
                            if (!vs[na][nb])
                            {
                                vs[na][nb] = 1;
                                q.push(mp(na, nb));
                            }
                        }
                    }
                }

                ans += 60 * len;
                ans += 500 * wid;
            }
        }
    }

    cout << ans;

}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
