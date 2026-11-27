#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {
    int d, p;
    cin >> d >> p;

    vector<pair<int, int>> A(p);
    for (auto& i : A) cin >> i.second >> i.first;
    sort(all(A));
    reverse(all(A));

    bitset<100001> bs;
    bs[0] = 1;
    for (auto& [c, l] : A) {
        bs |= bs << l;
        if (bs[d]) {
            cout << c << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}