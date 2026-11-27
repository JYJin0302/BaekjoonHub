#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char G[202][202];
char T[202][202];

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int u, v;
    cin >> u >> v;
    for (int i = 0; i < u; i++) {
        for (int j = 0; j < v; j++) {
            cin >> T[i][j];
        }
    }

    string mode;
    cin >> mode;

    if (mode[0] == 'c') {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                G[i][j] = T[min(i, u - 1)][min(j, v - 1)];
            }
        }
    }
    else if (mode[0] == 'r') {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                G[i][j] = T[i % u][j % v];
            }
        }
    }
    else if (mode[0] == 'm') {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i / u > 0) {
                    int p = i / u * u;
                    G[i][j] = G[2 * p - 1 - i][j];
                }
                else if (j / v > 0) {
                    int p = j / v * v;
                    G[i][j] = G[i][2 * p - 1 - j];
                }
                else {
                    G[i][j] = T[i][j];
                }
            }
        }
    }
    else  assert(0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << G[i][j];
        }
        cout << '\n';
    }


}