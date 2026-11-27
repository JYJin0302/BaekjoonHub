#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	while (n != 0) {

		ll ans = 0;
		stack<pair<ll, ll>> st; // pos, height

		st.push({ -1, 0 });
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;

			ll ti = i;
			while (st.top().second > x) {
				ll a, b;
				tie(a, b) = st.top();

				ans = max(ans, (i - a) * b);
				ti = a;
				st.pop();
			}

			if (st.top().second < x) {
				st.push({ ti, x });
			}
		}

		while (!st.empty()) {
			ll a, b;
			tie(a, b) = st.top();
			st.pop();

			ans = max(ans, (n - a) * b);
		}


		cout << ans << '\n';

		cin >> n;
	}
}