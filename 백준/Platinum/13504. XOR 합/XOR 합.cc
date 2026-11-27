#include <bits/stdc++.h>
using namespace std;

struct Trie {
	Trie* ch[2];
	bool ex;
	Trie() {
		ex = false;
		for (int i = 0; i < 2; i++) ch[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 2; i++) if (ch[i]) delete ch[i];
	}
	void insert(const int x, int pos = 30) {
		if (pos < 0) {
			this->ex = 1;
			return;
		}
		int now = (x & (1 << pos)) > 0;
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(x, pos-1);
		this->ex = 1;
	}

	int find(const int x, int pos = 30) {
		if (pos < 0) {
			return 0;
		}
		int now = (x & (1 << pos)) > 0;
		int op = 1 - now;

		int res = 0;
		if (ch[op] && ch[op]->ex) {
			//cout << "Found: " << pos << ' ' << op << '\n';
			return ch[op]->find(x, pos - 1) + (1 << pos);
		}
		return ch[now]->find(x, pos-1);
	}
};

void solve() {

	Trie* root = new Trie;
	root->insert(0);

	int curr = 0, ans = 0;
	int q;
	cin >> q;
	while (q--) {

		int x;
		cin >> x;

		curr ^= x;

		ans = max(ans, root->find(curr));
		root->insert(curr);
	}
	cout << ans << '\n';
	delete root;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}