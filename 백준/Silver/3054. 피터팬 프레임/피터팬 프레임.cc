#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

char G[5][100];
int dx[] = { -2, -1, 0, 1, 2, 1, 0, -1 };
int dy[] = { 0, 1, 2, 1, 0, -1, -2,-1 };

void solve() {

    string s;
    cin >> s;

    memset(G, '.', sizeof G);

    int n = s.size();
    for (int i = 0; i < n; i++) {
        int a = 2, b = 4 * i + 2;
        G[a][b] = s[i];
        for (int f = 0; f < 8; f++) {
            G[a + dx[f]][b + dy[f]] = '#';
        }
    }
    for (int i = 2; i < n; i += 3) {
        int a = 2, b = 4 * i + 2;
        for (int f = 0; f < 8; f++) {
            G[a + dx[f]][b + dy[f]] = '*';
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4 * n + 1; j++) {
            cout << G[i][j];
        }
        cout << '\n';
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}