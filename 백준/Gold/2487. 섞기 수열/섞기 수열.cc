#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll gcd(ll a, ll b) {
	if (b > a) swap(a, b);

	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N;
	cin >> N;

	vector<ll> pos(N + 1), cycle(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> pos[i];
	}

	for (int i = 1; i <= N; i++) {
		if (cycle[i] != 0) continue;

		vector<int> tt;

		ll t = i, cnt = 0;
		while (cycle[t] == 0) {
			cycle[t] = -1;
			tt.push_back(t);
			cnt++;
			t = pos[t];
		}

		for (int t : tt) cycle[t] = cnt;
	}

	ll gg = 1;
	for (int i = 1; i <= N; i++) {
		gg = gg * cycle[i] / gcd(gg, cycle[i]);
	}

	cout << gg;

}