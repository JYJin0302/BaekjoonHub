#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    vector<int> A(4);
    for (auto& i : A) cin >> i;
    sort(all(A));
    bool ok = 0;
    vector<vector<int>> tmp;
    tmp.push_back({ 0, 1, 2, 3 });
    tmp.push_back({ 0, 2, 4, 6 });
    tmp.push_back({ 1, 3, 5, 7 });
    tmp.push_back({ 0, 1, 4, 5 });
    tmp.push_back({ 2, 3, 6, 7 });
    tmp.push_back({ 4, 5, 6, 7 });
    for (auto f : tmp) if (f == A)ok = 1;

    if (ok) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}