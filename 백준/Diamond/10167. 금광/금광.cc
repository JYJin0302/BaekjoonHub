#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e15;

struct P {
	int x, y;
	ll val;

	bool operator<(P& other) {
		if (x == other.x) return y < other.y;
		return x < other.x;
	}
};

vector<vector<ll>> seg;
// 0 : left, 1 : right, 2 : all, 3 : ans

void update(int l, int r, int n, int u, ll new_val) {
	if (l > u || r < u) return;
	if (l == u && r == u) {
		seg[n][0] += new_val;
		seg[n][1] += new_val;
		seg[n][2] += new_val;
		seg[n][3] += max(0ll, new_val);
		return;
	}

	int m = (l + r) >> 1;
	update(l, m, n * 2, u, new_val);
	update(m + 1, r, n * 2 + 1, u, new_val);

	seg[n][0] = max(seg[n * 2][0], seg[n * 2][2] + seg[n * 2 + 1][0]);
	seg[n][1] = max(seg[n * 2 + 1][1], seg[n * 2][1] + seg[n * 2 + 1][2]);
	seg[n][2] = seg[n * 2][2] + seg[n * 2 + 1][2];
	seg[n][3] = max({ seg[n * 2][3], seg[n * 2 + 1][3], seg[n * 2][1] + seg[n * 2 + 1][0] });
}

vector<ll> ssum(int l, int r, int n, int sl, int sr) {

	vector<ll> res(4);
	if (l > sr || r < sl) {
		res = { -INF, -INF, -INF, -INF };
		return res;
	}
	if (l >= sl && r <= sr) return seg[n];

	int m = (l + r) >> 1;

	vector<ll> v1 = ssum(l, m, n * 2, sl, sr);
	vector<ll> v2 = ssum(m + 1, r, n * 2 + 1, sl, sr);

	res[0] = max(v1[0], v1[2] + v2[0]);
	res[1] = max(v2[1], v1[1] + v2[2]);
	res[2] = max(-INF, v1[2] + v2[2]);
	res[3] = max({ v1[3], v2[3], v1[1] + v2[0] });
	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<P> A(n);
	vector<int> xpos, ypos;
	for (auto& i : A) {
		cin >> i.x >> i.y >> i.val;
		xpos.push_back(i.x);
		ypos.push_back(i.y);
	}

	sort(xpos.begin(), xpos.end());
	sort(ypos.begin(), ypos.end());

	xpos.erase(unique(xpos.begin(), xpos.end()), xpos.end());
	ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());

	vector<pair<ll, ll>> xLst[3001];

	for (auto& i : A) {
		i.x = lower_bound(xpos.begin(), xpos.end(), i.x) - xpos.begin();
		i.y = lower_bound(ypos.begin(), ypos.end(), i.y) - ypos.begin();
		xLst[i.y].push_back({ i.x, i.val });
	}

	sort(A.begin(), A.end());

	/*
	for (auto i : xpos) cout << i << ' ';
	cout << '\n';
	for (auto i : ypos) cout << i << ' ';
	cout << '\n';
	for (auto i : A) cout << i.x << ' ' << i.y << ' ' << i.val << '\n';
	*/

	int sz = 1;
	ll ans = -INF;
	while (sz < xpos.size()) sz *= 2;
	for (int l = 0; l < ypos.size(); l++) {
		seg = vector<vector<ll>>(sz * 2, vector<ll>(4));
		for (int h = l; h < ypos.size(); h++) {
			// low, high


			for (auto i : xLst[h]) {
				ll a, b;
				tie(a, b) = i;

				update(0, sz - 1, 1, a, b);
			}

			/*
			cout << "SEG: " << l << ' ' << h << '\n';
			for (auto i : seg) {
				for (auto j : i) {
					cout << j << ' ';
				}
				cout << '\n';
			}*/

			vector<ll> res = ssum(0, sz - 1, 1, 0, sz - 1);
			ans = max(ans, res[3]);
		}
	}

	cout << ans;

}
