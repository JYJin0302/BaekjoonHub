#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


string A[11][11];

void solve() {

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> A[i][j];
        }
    }
    
    for (int i = 0; i < 10; i++) {
        bool ok = 1;
        for (int j = 1; j < 10; j++) {
            if (A[i][j] != A[i][0]) ok = 0;
        }
        if (ok) {
            cout << 1;
            return;
        }
        ok = 1;
        for (int j = 1; j < 10; j++) {
            if (A[j][i] != A[0][i]) ok = 0;
        }
        if (ok) {
            cout << 1;
            return;
        }
    }
    cout << 0;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}