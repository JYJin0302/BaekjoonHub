#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n;
    cin >> n;

    vector<string> A(n);
    for (auto& i : A) cin >> i;

    vector<int> cnt(26);
    for (auto f : A[0]) cnt[f - 'A']++;

    int ans = 0;

    for (int i = 1; i < n; i++) {
        vector<int> tc(26);
        for (auto f : A[i]) tc[f - 'A']++;

        int nd = 0, mr = 0;
        for (int j = 0; j < 26; j++) {
            if (tc[j] < cnt[j]) nd += cnt[j] - tc[j];
            else mr += tc[j] - cnt[j];
        }

        if (nd <= 1 && mr <= 1) ans++;
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