#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n;
    cin >> n;
    
    vector<int> A;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        auto ix = lower_bound(all(A), x) - A.begin();
        if (ix == A.size()) A.push_back(x);
        else A[ix] = x;
    }
    cout << A.size() << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}