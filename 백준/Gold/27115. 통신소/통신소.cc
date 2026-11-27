#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define x first
#define y second

bool ck[3001][3001];
int val[3001][3001];
vector<pair<int, int>> A[3010];

int dx[] = { -1, 0, 1 , 0 };
int dy[] = { 0, 1, 0, -1 };

int n, m, k;
bool inGrid(int tx, int ty) {
    return tx >= 1 && tx <= n && ty >= 1 && ty <= m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    while (k--) {

        int a, b, c;
        cin >> a >> b >> c;
        c++;

        val[a][b] = c;
        A[c].push_back({ a, b });
    }

    int curr = 3001;
    queue<pair<int, int>> q;
    while (curr > 0) {

        for (auto i : A[curr]) {
            if (!ck[i.x][i.y]) {
                ck[i.x][i.y] = 1;
                q.push(i);
            }
        }

        while (!q.empty()) {

            int a, b;
            tie(a, b) = q.front();

            if (val[a][b] != curr) break;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int na = a + dx[i];
                int nb = b + dy[i];

                if (inGrid(na, nb) && !ck[na][nb]) {
                    ck[na][nb] = 1;
                    val[na][nb] = curr - 1;
                    q.push({ na, nb });
                }
            }

        }

        curr--;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += (val[i][j] > 0);
        }
    }
    cout << ans;
}