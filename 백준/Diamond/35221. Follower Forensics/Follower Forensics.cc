#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[101010], rev[101010];
int root[101010];
int find(int n) {
	if (root[n] == n) return n;
	return root[n] = find(root[n]);
}

vector<pair<int, int>> TreeEdge[101010], rEdge[101010];

void merge(int u, int v, bool noAdd = 0) {
	int tu = find(u);
	int tv = find(v);

	if (tu == tv) rEdge[tu].push_back(mp(u, v));
	else {
		int szU = (int)TreeEdge[tu].size() + (int)rEdge[tu].size();
		int szV = (int)TreeEdge[tv].size() + (int)rEdge[tv].size();
		if (szU < szV) swap(tu, tv);
		root[tv] = tu;
		for (auto f : TreeEdge[tv]) TreeEdge[tu].push_back(f);
		for (auto f : rEdge[tv]) rEdge[tu].push_back(f);
		if (!noAdd) TreeEdge[tu].push_back(mp(u, v));
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> A(n), B(n);
	for (int i = 0; i < n; i++) { cin >> A[i]; }
	for (int i = 0; i < n; i++) { cin >> B[i]; }

	for (int i = 1; i <= n; i++) root[i] = i;

	int chk = 0;
	for (auto f : A) chk += f;
	for (auto f : B) chk -= f;
	if (chk) {
		cout << "impossible\n";
		return;
	}

	vector<array<int, 3>> pA(n);
	for (int i = 0; i < n; i++) pA[i] = {A[i], B[i], i};
	sort(all(pA));
	reverse(all(pA));

	set<array<int, 3>> st;
	for (int i = 0; i < n; i++)
		if (B[i]) st.insert({-B[i], -A[i], i});

	vector<pair<int, int>> edg;
	for (int i = 0; i < n; i++) {
		int a = pA[i][0];
		int b = pA[i][2];
		if (a == 0) continue;

		vector<int> lst;

		if(B[b]){
			auto tmp = st.find({-B[b], -A[b], b});
			st.erase(tmp);
		}

		auto iter = st.begin();
		while (a && iter != st.end()) {
			auto f = *iter;
			
			int d = f[2];
			a--;
			lst.push_back(d);
			iter++;
		}
		if (a) {
			cout << "impossible\n";
			return;
		}

		// cout << "Edg: " << b << " => ";
		// for (auto f : lst) cout << f << ' ';
		// cout << '\n';

		A[b] = 0;
		if(B[b]){
			st.insert({-B[b], 0, b});
		}

		for (auto f : lst) {
			edg.push_back(mp(b, f));
			st.erase(st.find({-B[f], -A[f], f}));
			B[f]--;
			if (B[f]) st.insert({-B[f], -A[f], f});
		}
	}

	// CC test

	for (auto [a, b] : edg) { merge(a, b); }

	vector<pair<int, int>> cLst;
	for (int i = 0; i < n; i++) {
		if (find(i) == i) cLst.push_back(mp((int)rEdge[i].size(), i));
	}
	sort(all(cLst));
	reverse(all(cLst));

	for (int j = 1; j < (int)cLst.size(); j++) {
		// merge two component
		int L = find(cLst[j - 1].y);
		int R = find(cLst[j].y);
		if (rEdge[L].empty() || TreeEdge[R].empty()) {
			cout << "impossible\n";
			return;
		}

		auto [a, b] = rEdge[L].back();
		rEdge[L].pop_back();
		auto [c, d] = TreeEdge[R].back();
		TreeEdge[R].pop_back();

		TreeEdge[L].push_back(mp(a, d));
		TreeEdge[L].push_back(mp(c, b));

		merge(L, R, 1);
	}

	int root = find(0);
	cout << n << ' ' << (int)TreeEdge[root].size() + (int)rEdge[root].size() << '\n';
	for (auto [a, b] : TreeEdge[root]) cout << a + 1 << ' ' << b + 1 << "\n";
	for (auto [a, b] : rEdge[root]) cout << a + 1 << ' ' << b + 1 << "\n";
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