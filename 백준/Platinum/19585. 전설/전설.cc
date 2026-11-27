#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool ok;
map<int, bool> cnt;

struct Trie {
	map<char, Trie*> ch;
	bool end;
	Trie() {
		end = false;
		ch.clear();
	}

	void insert(const char* s) {
		if (!*s) {
			this->end = true;
			return;
		}

		if (ch.find(*s) == ch.end()) ch[*s] = new Trie;
		ch[*s]->insert(s + 1);
	}
	void find(const char* s, int idx, int dir) {
		if (end) {
			if (dir == 1) {
				cnt[idx] = 1;
			}
			else {
				if (cnt[idx - 1] == 1) {
					ok = 1;
					return;
				}
			}
		}
		if (!*s) return;

		if (!ch[*s]) return;
		ch[*s]->find(s + 1, idx+dir, dir);
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);


	Trie* pre = new Trie;
	Trie* suf = new Trie;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		pre->insert(s.c_str());
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		reverse(s.begin(), s.end());
		suf->insert(s.c_str());
	}

	int q;
	cin >> q;
	while (q--) {

		string s;
		cin >> s;

		int sz = s.size();
		cnt.clear();
		ok = 0;

		pre->find(s.c_str(), -1, 1);

		reverse(s.begin(), s.end());
		suf->find(s.c_str(), sz, -1);

		if (ok) cout << "Yes\n";
		else cout << "No\n";
	}

}
