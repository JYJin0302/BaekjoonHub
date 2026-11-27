#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	vector<ll> A(n);
	for (auto& i : A) cin >> i;
	A.push_back(0);
	n++;

	ll ans = 0;
	stack<pair<ll, ll>> st;

	for (int i = 0; i < n; i++) {
		int ti = i;
		while (!st.empty() && st.top().first >= A[i]) {
			ans = max(ans, (i - st.top().second) * st.top().first);
			ti = st.top().second;
			st.pop();
		}
		if (st.empty() || st.top().first < A[i]) st.push({ A[i], ti });
	}
	cout << ans;

}