#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> root;
int find(int n) {
	if (root[n] == n) return n;
	return root[n] = find(root[n]);
}

vector<int> adj[30001];
int s[30001], e[30001];
int sz = 0;
int fw[60001];

int dep[30001];
int spt[16][30001];

void dfs(int v, int pv = -1) {
	s[v] = ++sz;
	for (auto i : adj[v]) if (i != pv) {
		dep[i] = dep[v] + 1;
		spt[0][i] = v;
		dfs(i, v);
	}
	e[v] = ++sz;
}

int lca(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);

	int df = dep[b] - dep[a];
	for (int i = 0; i < 16; i++) {
		if (df & (1 << i)) b = spt[i][b];
	}

	for (int i = 15; i >= 0; i--) {
		if (spt[i][a] != spt[i][b]) {
			a = spt[i][a], b = spt[i][b];
		}
	}

	if (a != b) a = spt[0][a];
	return a;
}

void update(int ix, int val) {
	if (ix == 0) return;
	while (ix <= sz) {
		fw[ix] += val;
		ix += ix & -ix;
	}
}

int ssum(int ix) {
	int res = 0;
	while (ix) {
		res += fw[ix];
		ix -= ix & -ix;
	}
	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> A(n + 1);
	for (int i = 1; i <= n; i++) cin >> A[i];

	root = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) root[i] = i;

	int q;
	cin >> q;

	vector<bool> isQ(q);
	vector<tuple<int ,int, int>> query(q);
	for (int i = 0; i < q; i++) {

		string s;
		int t, x, y;
		cin >> s >> x >> y;

		if (s[0] == 'b') t = 0;  // bridge
		else if (s[0] == 'p') t = 1;  // penguin
		else t = 2;  // excursion

		query[i] = { t, x, y };

		if (t == 0) {
			int tx = find(x), ty = find(y);
			if (tx != ty) {
				isQ[i] = 1;
				adj[x].push_back(y);
				adj[y].push_back(x);

				//cout << "ADD : " << x << ' ' << y << '\n';
				root[tx] = ty;
			}
		}
		else if (t == 2) {
			if (find(x) == find(y)) {
				isQ[i] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (s[i] == 0) dfs(i);
	}

	for (int i = 1; i < 16; i++) {
		for (int j = 1; j <= n; j++) {
			spt[i][j] = spt[i - 1][spt[i - 1][j]];
		}
	}

	for (int i = 1; i <= n; i++) {
		update(s[i], A[i]);
		update(e[i], -A[i]);
	}

	for (int i = 0; i < q; i++) {

		int t, a, b;
		tie(t, a, b) = query[i];

		if (t == 0) {
			if (!isQ[i]) {
				cout << "no\n";
			}
			else cout << "yes\n";
		}
		else if (t == 1) {
			int df = b - A[a];
			A[a] += df;
			update(s[a], df);
			update(e[a], -df);
		}
		else {
			if (!isQ[i]) {
				cout << "impossible\n";
				continue;
			}

			int lc = lca(a, b);

			int res = 0;
			res += ssum(s[a]) - ssum(s[lc]);
			res += ssum(s[b]) - ssum(s[lc]);
			res += A[lc];

			cout << res << '\n';
		}
	}
}