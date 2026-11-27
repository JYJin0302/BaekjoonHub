#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int dx[] = { -1, 0 ,1 ,0 , 1, 1, -1, -1 };
int dy[] = { 0, -1, 0, 1 , 1, -1, 1, -1 };

int n, m;
int A[2001][2001], dist[2001][2001];
bool v[2001][2001];
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    deque<pair<int, int>> q;
    for (int i = 1; i < n; i++) {
        v[i][0] = 1;
        if (A[i][0] == 0) {
            dist[i][0] = 1;
            q.push_back({ i, 0 });
        }
        else {
            q.push_front({ i, 0 });
        }
    }
    for (int i = 1; i < m-1; i++) {
        v[n-1][i] = 1;
        if (A[n-1][i] == 0) {
            dist[n-1][i] = 1;
            q.push_back({ n-1, i});
        }
        else {
            q.push_front({ n-1, i });
        }
    }

    v[0][0] = 1;
    v[n - 1][m - 1] = 1;

    int ans = 2;

    while (!q.empty()) {

        int a, b;
        tie(a, b) = q.front();
        q.pop_front();

        if (a == 0 || b == m - 1) {
            ans = min(ans, dist[a][b]);
            continue;
        }

        for (int i = 0; i < 8; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];

            if (inGrid(na, nb) && !v[na][nb]) {
                v[na][nb] = 1;
                if (A[na][nb] == 0) {
                    dist[na][nb] = dist[a][b] + 1;
                    q.push_back({ na, nb });
                }
                else {
                    dist[na][nb] = dist[a][b];
                    q.push_front({ na, nb });
                }
            }
        }
    }

    cout << ans;
}