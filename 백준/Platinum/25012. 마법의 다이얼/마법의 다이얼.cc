#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long findMinClicks(int M, int R, vector<pair<int, int>> P) {

	int N = P.size();

	sort(P.begin(), P.end());

	ll val0 = 0;
	map<ll, ll> mp;

	int ix = 0;
	while (ix < N) {

		int nx = ix;
		while (nx < N && P[ix].first == P[nx].first) {
			nx++;
		}

		ll a, b, m1, m2;
		for (int i = ix + 1; i < nx; i++) {

			a = P[i-1].second, b = P[i].second;

			if ((a + b) % 2 == 1) {
				m1 = (a + b) / 2, m2 = m1 + 1;
				mp[a]++;
				mp[m1]--;
				mp[m2]--;
				mp[b]++;
			}
			else {
				m1 = (a + b) / 2, m2 = m1;
				mp[a]++;
				mp[m1]--;
				mp[m2]--;
				mp[b]++;
			}

			//cout << "add: " << a << ' ' << m1 << ' ' << m2 << ' ' << b << '\n';
		}

		a = P[nx - 1].second, b = P[ix].second;
		if ((a + b+R) % 2 == 1) {
			m1 = (a + b + R) / 2, m2 = m1 + 1;
			mp[a]++;
			if (m1 >= R) mp[0]++;
			mp[m1%R]--;
			mp[m2%R]--;
			if (m2 < R) mp[0]--;
			mp[b]++;
		}
		else {
			m1 = (a + b + R) / 2, m2 = m1;
			mp[a]++;
			if (m1 >= R) mp[0]++;
			mp[m1 % R]--;
			mp[m2 % R]--;
			if (m2 < R) mp[0]--;
			mp[b]++;
		}
		//cout << "add: " << a << ' ' << m1 << ' ' << m2 << ' ' << b << '\n';

		val0 += min(R - a, b);
		ix = nx;

		/*cout << "Current state:\n";
		cout << val0 << ' ';
		ll tmp = 0;
		for (auto i : mp) {
			cout << i.first << "=>" << tmp + i.second << ' ';
			tmp += i.second;
		}
		cout << '\n';*/
	}

	mp[R - 1] += 0;

	ll ans = val0;
	ll df = 0, pv = 0;

	for (auto i : mp) {
		ll a, b;
		tie(a, b) = i;

		val0 += (a - pv) * df;
		df += b;
		pv = a;

		ans = min(ans, val0);
	}
	return ans;
}

