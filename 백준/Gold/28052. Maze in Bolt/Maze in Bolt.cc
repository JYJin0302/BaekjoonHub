#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
string s;
char A[1010][111];
bool vs[1010][111];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0 ,1, 0, -1 };

bool inGrid(int x, int y) {
    return x >= 0 && x <= n && y >= 0 && y < m;
}
bool isValid(int x, int y) {

    for (int j = 0; j < m; j++) {
        int ty = (y + j) % m;
        if (A[x][ty] == '1' && s[j] == '1') return 0;
    }
    return 1;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(A, '0', sizeof(A));

    cin >> n >> m;
    cin >> s;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    vs[0][0] = 1;
    while (!q.empty()) {

        int a, b;
        tie(a, b) = q.front();
        q.pop();

        if (a == n) {
            cout << 'Y';
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int na = a + dx[i];
            int nb = (b + dy[i] + m) % m;

            if (inGrid(na, nb) && !vs[na][nb] && isValid(na, nb)) {
                vs[na][nb] = 1;
                q.push({ na, nb });
            }
        }
    }

    reverse(s.begin(), s.end());
    q.push({ 0, 0 });

    memset(vs, 0, sizeof(vs));
    vs[0][0] = 1;
    while (!q.empty()) {

        int a, b;
        tie(a, b) = q.front();
        q.pop();

        if (a == n) {
            cout << 'Y';
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int na = a + dx[i];
            int nb = (b + dy[i] + m) % m;

            if (inGrid(na, nb) && !vs[na][nb] && isValid(na, nb)) {
                vs[na][nb] = 1;
                q.push({ na, nb });
            }
        }
    }


    cout << 'N';
}