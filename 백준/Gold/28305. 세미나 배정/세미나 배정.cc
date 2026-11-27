#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, t;
    cin >> n >> t;

    vector<ll> A(n);
    for (auto& i : A) cin >> i;
    sort(A.begin(), A.end());

    int l = 1, r = n, ans = n;
    while (l <= r) {

        int md = (l + r) / 2;
        queue<ll> q; // 세미나 끝나는시간
        bool ok = 1;
        for (auto i : A) {

            while (!q.empty() && q.front() <= i-t) q.pop();
            if (q.size() < md) {
                q.push(max(i, t));
                continue;
            }
            ll tp = q.front();

            if (tp >= i) {
                ok = 0;
                break;
            }

            q.pop();
            q.push(max(tp + t, i));

        }
       // cout << md << ' ' << ok << '\n';
        if (ok) {
            ans = md;
            r = md - 1;
        }
        else l = md + 1;
    }

    cout << ans;

}