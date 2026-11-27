#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {
    int n;
    cin >> n;

    string tar = "ZNA";
    for (int i = 0; i < 3 * n; i++) {
        for (int j = 0; j < 3 * n; j++) {
            cout << tar[(i + j/n) % 3];
        }
        cout << '\n';
    }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}