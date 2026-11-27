#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, s;
	cin >> n >> m >> s;

	vector<ll> A(n), B(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i] >> B[i];
	}

	vector<pair<ll, ll>> C(n);
	for (int i = 0; i < n; i++) {
		C[i] = { A[i], i };
	}
	sort(C.rbegin(), C.rend());

	ll ans = 0;
	vector<bool> usedA(n), usedB(n);
	for (int i = 0; i < m + s; i++) {
		usedA[C[i].second] = 1;
		ans += A[C[i].second];
	}

	priority_queue<pair<ll, ll>> pq1, pq2, pq3;

	for (int i = 0; i < n; i++) {
		if (usedA[i]) {
			pq1.push({ B[i] - A[i], i });
			pq2.push({ -A[i], i });
		}
		else {
			pq3.push({ B[i], i });
		}
	}

	for (int i = 0; i < s; i++) {
		while (!pq1.empty()) {
			if (!usedA[pq1.top().second]) pq1.pop();
			else break;
		}
		while (!pq2.empty()) {
			if (!usedA[pq2.top().second]) pq2.pop();
			else break;
		}
		while (!pq3.empty()) {
			if (usedB[pq3.top().second]) pq3.pop();
			else break;
		}

		ll v1 = 0, v2 = 0;
		ll a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
		if (!pq1.empty()) tie(a, b) = pq1.top();
		if (!pq2.empty()) tie(c, d) = pq2.top();
		if (!pq3.empty()) tie(e, f) = pq3.top();

		v1 = a;
		v2 = c + e;

		if (v1 >= v2) {
			usedB[b] = 1;
			usedA[b] = 0;

			ans += v1;
		}
		else {

			usedA[d] = 0;
			pq3.push({ B[d], d });

			usedB[f] = 1;

			ans += v2;
		}
	}
	cout << ans;

}