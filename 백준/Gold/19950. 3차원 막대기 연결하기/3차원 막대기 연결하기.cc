#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;


    int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    int l = 0, r = 0;
    for (auto f : A) {
        int nr = r + f;
        int nl = 0;
        if (l <= f && f <= r) nl = 0;
        else {
            nl = min(abs(l - f), abs(r - f));
        }

        l = nl, r = nr;
    }

    l = l * l;
    r = r * r;
    if (l <= d && d <= r) {
        cout << "YES\n";
    }
    else cout << "NO\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}