#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int n;
    cin >> n;

    vector<int> inp(n);
    for (int i = 1; i < n; i++) {
        cout << "? " << i - 1 << " -1 " << i << " -1" << endl;
        cin >> inp[i];
    }

    vector<int> ans(n);
    for (int i = 1; i <= 1000; i++) {
        ans[0] = i;
        
        int mx = i;
        bool ok = 1;
        vector<bool> cnt(1010);
        cnt[i] = 1;
        for (int j = 1; j < n; j++) {
            ans[j] = ans[j - 1] ^ inp[j];
            mx = max(mx, ans[j]);
            if (ans[j] > 1000 || ans[j] == 0) {
                ok = 0;
                break;
            }
            cnt[ans[j]] = 1;
        }

        // test
        int res = 1;
        while (cnt[res]) res++;
        if (ok && res == mx + 1) {
            cout << "! ";
            for (auto f : ans) cout << f << ' ';
            cout << endl;
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