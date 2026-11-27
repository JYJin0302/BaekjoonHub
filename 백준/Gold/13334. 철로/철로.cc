#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	ll n, a, b, d;
	cin >> n;

	vector<pair<ll, ll>> A(n);
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		A[i] = { min(a, b), max(a, b) };
	}
	cin >> d;

	vector<pair<ll ,ll>> B;
	for (auto i : A) {
		tie(a, b) = i;
		if (b - a > d) continue;

		B.push_back({ b, 0ll });  // +1
		B.push_back({ a + d, 1ll });  // -1
	}

	sort(B.begin(), B.end());

	ll ans = 0;
	ll curr = 0;
	for (auto i : B) {
		tie(a, b) = i;

		if (b == 0) curr++;
		else curr--;
		ans = max(ans, curr);
	}

	cout << ans;

}