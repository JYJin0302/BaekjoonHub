#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> seg;

void update(ll l, ll r, ll n, ll diff) {
	if (l > diff || r < diff) return;

	if (l == diff && r == diff) {
		seg[n]++;
		return;
	}
	ll mid = (l + r)/2;

	update(l, mid, n * 2, diff);
	update(mid + 1, r, n * 2 + 1, diff);
	seg[n]++;
}
int subsum(ll l, ll r,ll n, ll sl, ll sr) {
	if (l > sr || r < sl) return 0;

	if (l >= sl && r <= sr) return seg[n];

	ll mid = (l + r) / 2;
	
	return subsum(l, mid, n * 2, sl, sr) + subsum(mid + 1, r, n * 2 + 1, sl, sr);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, a, b, cnt = 0;
	cin >> n;

	ll size = 1;
	while (size < n) size *= 2;

	seg = vector<ll>(size * 2);

	vector<pair<ll, ll>>A;
	for (int i = 0; i < n; i++) {
		cin >> a;
		A.push_back({ -a ,-i });
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < n; i++) {
		tie(a, b) = A[i];
		a *= -1;
		b *= -1;

		ll temp = subsum(size, size * 2 - 1, 1, size, size + b);
		cnt += n - 1 - i- b + temp  ;
		update(size, size*2-1, 1, size + b);

	}

	cout << cnt;
}