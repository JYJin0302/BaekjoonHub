#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int G[1010][1010];

void solve(int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }

    bool ok = 1;
    for (int i = 1; i < n; i++) {
        int d = G[i][0] - G[i - 1][0];

        for (int j = 1; j < n; j++) {
            if (G[i][j] - G[i - 1][j] != d) ok = 0;
        }
    }

    if (ok) {
        cout << "homogeneous\n";
        return;
    }

    cout << "not homogeneous\n";
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;

    int n;
    cin >> n;
    while (n) {
        
        solve(n);
        cin >> n;
    }
}