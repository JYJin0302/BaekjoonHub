#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[101010], rev[101010];
int inD[101010];
void solve() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int x;
			cin >> x;
			adj[i].push_back(x);
			rev[x].push_back(i);
			inD[x]++;
		}
	}

	vector<pair<int, int>> A(n);
	for (int i = 1; i <= n; i++) { A[i-1] = mp(inD[i], i); }
	sort(all(A));
	reverse(all(A));

	vector<bool> G(n);
	int err = 0;
	int eCnt = 0;

	int res = -1;

	for (int i = 0; i < n - 1; i++) {
		int v = A[i].y;
		G[v] = 1;
		for (auto f : adj[v]) {
			if (G[f]) {
				eCnt--;
			} else {
				err++;
			}
		}

		for (auto f : rev[v]) {
			if (G[f]) {
				err--;
			} else {
				eCnt++;
			}
		}

		if (1ll * (i + 1) * (n - i - 1) == eCnt && err == 0) { res = i; }
	}

	vector<int> ans;
	for (int i = res + 1; i < n; i++) { ans.push_back(A[i].y); }
	sort(all(ans));

	cout << (int)ans.size() << ' ';
	for (auto f : ans) cout << f << ' ';
	cout << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}