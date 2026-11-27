#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll mod = 1e9 + 7;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		
		priority_queue<ll> pq;
		for (int i = 0; i < n; i++) {
			ll temp;
			cin >> temp;
			pq.push(-temp);
		}

		ll ans = 1;
		while (pq.size() > 1) {
			ll a = pq.top();
			pq.pop();
			ll b = pq.top();
			pq.pop();
			ans *= (a * b) % mod;
			ans %= mod;
			pq.push(-a * b);

		}
		cout << ans << '\n';
	}

}