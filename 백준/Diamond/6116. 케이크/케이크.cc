#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<pair<int, int>> q[100010];

void solve() {

    int n;
    cin >> n;

    vector<int> A(n+1), sA(n+1);
    for (int i = 0; i < n; i++) cin >> A[i];

    reverse(A.begin(), A.end());
    for (int i = 1; i <= n; i++) sA[i] = sA[i - 1] + A[i];

    vector<int> dp_len(n + 1), dp_h(n + 1);

    priority_queue<pair<int, int>> pq;
    pq.push({ 0, 0 });

    for (int i = 1; i <= n; i++) {
        for (auto j : q[i]) pq.push(j);

        int a, b;
        tie(a, b) = pq.top();

        //cout << "CURr: " << i << ' ' << a << ' ' << b << '\n';

        dp_len[i] = sA[i] - a;
        dp_h[i] = dp_h[b] + 1;

        int nval = dp_len[i] + sA[i];

        int nx = lower_bound(sA.begin(), sA.end(), nval) - sA.begin();
        //cout << nval << ' ' << nx << '\n';
        q[nx].push_back({ sA[i], i });
    }

  //  for (int i = 1; i <= n; i++) cout << dp_len[i] << ' ' << dp_h[i] << '\n';

    cout << dp_h[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t= 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}