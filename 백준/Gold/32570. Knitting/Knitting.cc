#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> lst[303030];

void solve() {
	int n, k, p;
	cin >> n >> k >> p;

	int m;
	cin >> m;
	vector<int> A(m);
	for (auto& i : A) cin >> i;

	set<pair<int, int>> st;
	for (int i = 1; i <= k; i++) st.insert(mp(-1, i));

	vector<int> pre(k + 1, -1);

	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		int nxt = 0;
		if (i < m) {
			nxt = A[i];
		} else {
			nxt = (*st.begin()).y;
		}
		if (pre[nxt] == -1 || pre[nxt] <= i - p) {
			ans[i] = nxt;
			st.erase(st.find(mp(pre[nxt], nxt)));
			pre[nxt] = i;
			st.insert(mp(pre[nxt], nxt));
		} else {
			cout << "impossible\n";
			return;
		}
	}

	vector<int> freq(k + 1);
	// possible
	ans = vector<int>(n);
	pre = vector<int>(k + 1, -1);
	for (int j = m - 1; j >= 0; j--) {
		int v = A[j];
		freq[v]++;
		if (pre[v] == -1) {
			pre[v] = j;
			lst[max(m, j + p)].push_back(v);
		}
		ans[j] = v;
	}
	for (int i = 1; i <= k; i++) {
		if (pre[i] == -1) { lst[m].push_back(i); }
	}

	st.clear();
	for (int i = m; i < n; i++) {
		for (auto f : lst[i]) st.insert(mp(freq[f], f));
		auto [a, b] = *st.begin();
		st.erase(st.begin());
		freq[b]++;
		ans[i] = b;
		lst[i + p].push_back(b);
	}

	for (auto f : ans) cout << f << ' ';
	cout << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}