#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

struct Node {
	int ch[26];
	Node() { memset(ch, 0, sizeof ch); }
};

Node A[2002020];
int T = 0;
int insert(int cur, string& s, int idx) {
	if (idx == (int)s.size()) return cur;
	int nxt = s[idx] - 'a';
	if (!A[cur].ch[nxt]) { A[cur].ch[nxt] = ++T; }
	return insert(A[cur].ch[nxt], s, idx + 1);
}

int In[2002020];
int Out[2002020];
void dfs(int v) {
	In[v] = ++T;
	for (int i = 0; i < 26; i++) {
		if (A[v].ch[i]) { dfs(A[v].ch[i]); }
	}
	Out[v] = T;
}

ll fw[2002020];
void update(int ix, ll val) {
	while (ix <= 2000020) {
		fw[ix] += val;
		ix += ix & -ix;
	}
}
ll getS(int ix) {
	ll res = 0;
	while (ix) {
		res += fw[ix];
		ix -= ix & -ix;
	}
	return res;
}

int findIdx(int cur, string& s, int idx) {
	if (idx == (int)s.size()) return cur;

	int nxt = s[idx] - 'a';
	if (!A[cur].ch[nxt]) return -1;
	return findIdx(A[cur].ch[nxt], s, idx + 1);
}

void solve() {
	int n, q;
	cin >> n >> q;

	vector<int> pos(n + 1);

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		reverse(all(s));
		pos[i + 1] = insert(0, s, 0);
	}

	T = 0;
	dfs(0);

	vector<ll> W(n + 1);
	for (int i = 1; i <= n; i++) {
		ll w;
		cin >> w;
		W[i] = w;

		int L = In[pos[i]], R = Out[pos[i]];
		//cout << "UPD: " << L << ' ' << R << ' ' << w << '\n';
		update(L, w);
	}

	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int ix;
			ll w;
			cin >> ix >> w;

			ll dif = w - W[ix];
			W[ix] = w;

			int L = In[pos[ix]], R = Out[pos[ix]];
			update(L, dif);
		} else {
			string s;
			cin >> s;

			reverse(all(s));
			int ix = findIdx(0, s, 0);
			if (ix == -1) cout << 0 << '\n';
			else {
				int L = In[ix], R = Out[ix];
				ll res = getS(R) - getS(L - 1);
				cout << res * (int)s.size() << '\n';
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}