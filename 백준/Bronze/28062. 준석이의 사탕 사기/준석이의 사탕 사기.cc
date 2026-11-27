#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    vector<int> od;
    int tot = 0;
    for (auto f : A) {
        tot += f;
        if (f & 1) od.push_back(f);
    }

    sort(all(od));

    if (tot & 1) {
        tot -= od[0];
    }
    cout << tot;



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}