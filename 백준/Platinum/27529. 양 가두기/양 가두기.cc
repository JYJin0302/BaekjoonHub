#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, ll> ntoi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<ll, ll>> A(n);
	vector<ll> B(n);
	for (int i = 0; i < n; i++) {
		ll a, b; 
		cin >> a >> b; 
		A[i] = { a, b };
		B[i] = a;
	}

	sort(B.begin(), B.end());
	B.erase(unique(B.begin(), B.end()), B.end());
	for (int i = 0; i < B.size(); i++) {
		ntoi[B[i]] = i;
	}

	vector<ll> Mh(n, -1e9), mh(n, 1e9);

	for (auto i : A) {
		ll a, b;
		tie(a, b) = i;

		int ai = ntoi[a];
		Mh[ai] = max(Mh[ai], b);
		mh[ai] = min(mh[ai], b);
	}

	vector<ll> RMax(n+1), RMin(n+1);

	int tsz = B.size();
	RMax[tsz] = -1e9;
	RMin[tsz] = 1e9;
	for (int i = B.size() - 1; i >= 0; i--) {
		RMax[i] = max(RMax[i + 1], Mh[i]);
		RMin[i] = min(RMin[i + 1], mh[i]);

		//cout << RMax[i] << ' ' << RMin[i] << '\n';
	}

	ll up, dw;
	int ix = 0;

	ll ans_len = 0, ans_area = 0;
	ll pv = B[ix];

	up = Mh[ix], dw = mh[ix];
	ans_len += up - dw + 1;
	ix++;

	//cout << "INit: " << up << ' ' << dw << '\n';
	while (ix < B.size()) {
		ll nup = up, ndw = dw;

		if (RMax[ix] < up) {
			// 아래로 꺾
			nup = RMax[ix];
			ndw = min(nup, ndw);
		}
		if (RMin[ix] > dw) {
			// 위로 꺾
			ndw = RMin[ix];
			nup = max(nup, ndw);
		}

		//nup = min(nup, RMax[ix]);
		//ndw = max(ndw, RMin[ix]);

		//cout << "RM: " << RMax[ix] << ' ' << RMin[ix] << '\n';
		ans_len += 2;
		ans_len += abs(nup - up) + abs(ndw - dw);

		ll tu = max(nup, up);
		ll td = min(ndw, dw);
		ans_area += tu - td + 1;

		up = nup, dw = ndw;
		//cout << "MID: " << ix << ' ' << up << ' ' << dw << '\n';

		nup = max(up, Mh[ix]);
		ndw = min(dw, mh[ix]);

		ll curr = B[ix];
		
		ll row_dist = curr - pv - 1;

		ans_len += 2 * row_dist;
		ans_area += row_dist * (up - dw+1);
		ans_len += abs(nup - up) + abs(ndw- dw);

		up = nup;
		dw = ndw;

		//cout << "FIN: "<<  ix << ' ' << up << ' ' << dw << '\n';

		ix++;
		pv = curr;
	}

	ans_len += 2 + up - dw + 1;
	ans_area += up - dw + 1;
	cout << ans_len << ' ' << ans_area;
}