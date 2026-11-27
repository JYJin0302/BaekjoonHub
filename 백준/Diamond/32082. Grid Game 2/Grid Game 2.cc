#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


int getNum(int x, int y) {
    
    if (x > y) swap(x, y);
    if (x == 0) return 0;

    int v = (y / x) % 2;
    return v ^ getNum(y % x, x);
}

void solve() {

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        int res = getNum(x, y) ^ getNum(x - 1, y) ^ getNum(x, y - 1) ^ getNum(x - 1, y - 1);
        ans ^= res;
    }

    if (ans) cout << "FIRST\n";
    else cout << "SECOND\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}