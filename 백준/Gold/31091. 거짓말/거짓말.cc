#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


void solve() {

    int n;
    cin >> n;

    vector<int> pos, neg;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 0) pos.push_back(x);
        else neg.push_back(-x);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    vector<int> ans;

    int ix0 = 0, ix1 = 0;
    for (int i = 0; i <= n; i++) {
        while (ix0 < pos.size() && pos[ix0] <= i) ix0++;
        while (ix1 < neg.size() && neg[ix1] < i) ix1++;

        int tot = pos.size() - ix0 + ix1;
        if (tot == i) ans.push_back(i);

    }
    cout << ans.size() << '\n';
    for (auto f : ans) cout << f << ' ';
    cout << '\n';

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    return 0;
}