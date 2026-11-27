#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> A;
    vector<int> num;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        if (a > b)swap(a, b);
        A.push_back(mp(a, b));
        num.push_back(a);
        num.push_back(b);
    }
    sort(all(num));
    
    for (auto& [a, b] : A) {
        a = lower_bound(all(num), a) - num.begin();
        b = lower_bound(all(num), b) - num.begin();
    }

    ll ans = 0;
    for (int i = 0; i < m; i++) {
        vector<int> L, R;
        for (int j = 0; j < m; j++) {
            if (A[j].x < A[i].x && A[j].y < A[i].y && A[j].y > A[i].x) L.push_back(A[j].y);
            if (A[j].x > A[i].x && A[j].x < A[i].y && A[j].y > A[i].y) R.push_back(A[j].x);
        }

        vector<int> cnt(m * 2);
        for (auto f : L) cnt[f]++;
        for (int i = 1; i < m * 2; i++) cnt[i] += cnt[i - 1];

        for (auto f : R) {
            ans += cnt[m * 2 - 1] - cnt[f];
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}