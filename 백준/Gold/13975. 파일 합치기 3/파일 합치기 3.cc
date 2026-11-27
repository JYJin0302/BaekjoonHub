#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        priority_queue<ll> pq;
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            pq.push(-a);
        }

        ll ans = 0;
        while (pq.size() >= 2) {
            ll a, b;
            a = pq.top(); pq.pop();
            b = pq.top(); pq.pop();

            ans += -a - b;
            pq.push(a + b);
        }

        cout << ans << '\n';
    }
}