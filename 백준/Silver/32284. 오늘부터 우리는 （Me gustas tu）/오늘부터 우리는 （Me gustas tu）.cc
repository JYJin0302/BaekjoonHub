#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n, m;
    cin >> n >> m;

    int sx, sy;
    cin >> sx >> sy;


    for(int i =0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if (i < sx) {
                cout << 'S';
            }
            else if (i == sx) {
                if (j < sy) cout << 'E';
                else cout << 'W';
            }
            else {
                cout << 'N';
            }
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