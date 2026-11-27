#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
typedef long long ll;

#define mp make_pair

void solve() {
	int n;
	cin >> n;
	vector<int> A(n + 1);
	for (int i = 1; i <= n; i++) cin >> A[i];

	vector<pair<int, int>> ans1, ans2;

	vector<int> cyc;

	vector<bool> vis(n + 1);
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		// cout << "Go ; " << i << endl;

		vector<int> route;
		int cur = i;
		while (!vis[cur]) {
			// cout << "Vis : " << cur << endl;
			vis[cur] = 1;
			route.push_back(cur);
			cur = A[cur];
		}

		while ((int)route.size() >= 4) {
			int ix1 = route.back();
			int ix2 = route[(int)route.size() - 3];
			swap(A[ix1], A[ix2]);
			ans1.push_back(mp(ix1, ix2));

			route.pop_back();
			route.pop_back();
		}

		if ((int)route.size() == 3) {
			if (cyc.empty()) {
				cyc = route;
			} else {
				int a = cyc[0], b = cyc[1], c = cyc[2];
				int d = route[0], e = route[1], f = route[2];

				ans1.push_back(mp(b, e));
				swap(A[b], A[e]);
				ans1.push_back(mp(b, c));
				swap(A[b], A[c]);
				ans1.push_back(mp(e, f));
				swap(A[e], A[f]);
				cyc.clear();
			}
		}
	}

	vis = vector<bool>(n + 1);
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vector<int> route;
		int cur = i;
		while (!vis[cur]) {
			vis[cur] = 1;
			route.push_back(cur);
			cur = A[cur];
		}

		if ((int)route.size() == 2) {
			ans2.push_back(mp(route[0], route[1]));
		} else if ((int)route.size() == 3) {
			ans2.push_back(mp(route[0], route[1]));
			ans2.push_back(mp(route[0], route[2]));
		} else {
			assert(0);
		}
	}

	cout << "YES\n";
	cout << (int)ans1.size() << '\n';
	for (auto [a, b] : ans1) {
		if (a > b) swap(a, b);
		cout << a << ' ' << b << '\n';
	}
	cout << (int)ans2.size() << '\n';
	for (auto [a, b] : ans2) {
		if (a > b) swap(a, b);
		cout << a << ' ' << b << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}