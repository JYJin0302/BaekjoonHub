#include <bits/stdc++.h>
using namespace std;

struct Trie {
	Trie* ch[2];
	int cnt;
	bool ex;
	Trie() {
		cnt = 0;
		ex = false;
		for (int i = 0; i < 2; i++) ch[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 2; i++) if (ch[i]) delete ch[i];
	}
	void insert(const int x, int pos = 29) {
		if (pos < 0) {
			this->cnt++;
			this->ex = 1;
			return;
		}
		int now = (x & (1 << pos)) > 0;
		if (!ch[now]) ch[now] = new Trie;
		ch[now]->insert(x, pos-1);
		this->ex = 1;
	}
	void del(const int x, int pos = 29) {
		if (pos < 0) {
			this->cnt--;
			if (this->cnt == 0) this->ex = 0;
			return;
		}
		int now = (x & (1 << pos)) > 0;
		ch[now]->del(x, pos - 1);
		
		if (!ch[0]) ch[0] = new Trie;
		if (!ch[1]) ch[1] = new Trie;
		this->ex = ch[0]->ex || ch[1]->ex;
	}
	int find(const int x, int pos = 29) {
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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Trie* root = new Trie;
	root->insert(0);

	int q;
	cin >> q;
	while (q--) {

		int t, x;
		cin >> t >> x;

		if (t == 1) {
			root->insert(x);
		}
		else if (t == 2) {
			root->del(x);
		}
		else {
			cout << root->find(x) << '\n';
		}

	}

}