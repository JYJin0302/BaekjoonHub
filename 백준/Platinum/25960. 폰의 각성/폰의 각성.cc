#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n;
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

int dnx[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
int dny[] = { -2, -2, -1, 1, 2, 2, 1, -1 };

char A[1001][1001];
int dp[1001][1001];


bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    int sx, sy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
            dp[i][j] = -1;
            if (A[i][j] == 'P') {
                sx = i, sy = j;
            }
        }
    }

    int ans = -1;

    priority_queue<tuple<int, int, int>> pq;
    pq.push({ 0, sx, sy });
    while (!pq.empty()) {

        int v, a, b;
        tie(v, a, b) = pq.top();
        pq.pop();

        if (dp[a][b] != -1) continue;
        dp[a][b] = -v;

        char c = A[a][b];

        switch (c) {

        case 'P':
            A[a][b] = '0';
            dp[a][b] = -1;
            for (int i = 0; i < 8; i++) {
                int na = a + dx[i];
                int nb = b + dy[i];

                if (inGrid(na, nb) && dp[na][nb] == -1 && A[na][nb] != '0') {
                    pq.push({ v - 1, na, nb });
                }
            }

            break;
        case 'Q':
            for (int i = 0; i < 8; i++) {
                int na = a + dx[i];
                int nb = b + dy[i];

                int cnt = 1;
                while (inGrid(na, nb) && dp[na][nb] == -1) {
                    if (A[na][nb] != '0') {
                        pq.push({ v - cnt, na, nb });
                        break;
                    }
                    cnt++;
                    na += dx[i];
                    nb += dy[i];
                }
            }
            break;

        case 'B':
            for (int i = 1; i < 8; i+=2) {
                int na = a + dx[i];
                int nb = b + dy[i];

                int cnt = 1;
                while (inGrid(na, nb) && dp[na][nb] == -1) {
                    if (A[na][nb] != '0') {
                        pq.push({ v - cnt, na, nb });
                        break;
                    }
                    cnt++;
                    na += dx[i];
                    nb += dy[i];
                }
            }
            break;


        case 'R':
            for (int i = 0; i < 8; i+=2) {
                int na = a + dx[i];
                int nb = b + dy[i];

                int cnt = 1;
                while (inGrid(na, nb) && dp[na][nb] == -1) {
                    if (A[na][nb] != '0') {
                        pq.push({ v - cnt, na, nb });
                        break;
                    }
                    cnt++;
                    na += dx[i];
                    nb += dy[i];
                }
            }
            break;

        case 'N':
            for (int i = 0; i < 8; i++) {
                int na = a + dnx[i];
                int nb = b + dny[i];

                if (inGrid(na, nb) && dp[na][nb] == -1 && A[na][nb] != '0') {
                    pq.push({ v - 2, na, nb });
                }
            }
            break;

        case 'K':
            ans = -v;
            break;
        }
    }

    cout << ans;
}