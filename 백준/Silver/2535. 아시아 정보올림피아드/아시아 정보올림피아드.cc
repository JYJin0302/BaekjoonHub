#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> A;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        A.push_back(mp(c, mp(a, b)));
    }
    sort(A.rbegin(), A.rend());

    int t = 3;
    vector<int> cnt(111);
    for (auto f : A) {
        auto [a, b] = f.second;
        if (cnt[a] == 2) continue;
        cnt[a] ++;

        cout << a << ' ' << b << '\n';
        t--;
        if (t == 0) break;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}