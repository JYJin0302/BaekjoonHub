#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int price[20202];

void solve() {

    int n;
    cin >> n;

    int res = 10000;
    while (n--) {
        int p, x, f;
        cin >> p >> x >> f;
        x *= f;

        if ((price[p] < 0 && x > 0) || (price[p] > 0 && x < 0)) {
            res = p;
        }
        price[p] += x;
    }
    cout << res;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}