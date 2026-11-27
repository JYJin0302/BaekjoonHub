#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n;
    cin >> n;

    int ans = 0;
    int g0 = 0, g1 = 0;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int cnt0 = 0, cnt1 = 0;
        for (auto f : s) {
            if (f == '0') cnt0++;
            else cnt1++;
        }
        A[i] = mp(cnt0, cnt1);
        ans += min(cnt0, cnt1);
        if (cnt0 > cnt1) g0++;
        else if (cnt0 < cnt1) g1++;
    }

    if (ans == 0) {
        cout << 0 << '\n';
        return;
    }

    if (g0 == n) {
        int dif = 5050505;
        for (int j = 0; j < n; j++) {
            dif = min(dif, A[j].first - A[j].second);
        }
        ans += dif;
    }
    else if (g1 == n) {
        int dif = 5050505;
        for (int j = 0; j < n; j++) {
            dif = min(dif, A[j].second - A[j].first);
        }
        ans += dif;
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}