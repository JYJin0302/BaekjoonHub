#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Trie {
	Trie* ch[26];
	ll val, mxVal;

	Trie() {
		val = 0;
		mxVal = 0;
		for (int i = 0; i < 26; i++) ch[i] = NULL;
	}
	~Trie() {
		for (int i = 0; i < 26; i++) if (ch[i]) delete ch[i];
	}
	void insert(const char* s, ll v) {
		if (!*s) {
			this->val = v;
		}
		else {
			int now = *s - 'a';
			if (!ch[now]) ch[now] = new Trie;
			ch[now]->insert(s + 1, v);
		}

		ll newdp = max(0ll, this->val);
		for (int i = 0; i < 26; i++) {
			if (ch[i]) newdp = max(newdp, this->val + ch[i]->mxVal);
		}
		this->mxVal = newdp;
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Trie* pre1 = new Trie;
	Trie* pre2 = new Trie;
	Trie* suf1 = new Trie;
	Trie* suf2 = new Trie;

	int q;
	cin >> q;
	while (q--) {

		char c;
		cin >> c;

		if (c == '+') {
			ll ans = 0;
			ans += max(0ll, pre1->mxVal);
			ans += max(0ll, suf1->mxVal);
			cout << ans << '\n';
		}
		else if (c == '-') {
			ll ans = 0;
			ans += max(0ll, pre2->mxVal);
			ans += max(0ll, suf2->mxVal);
			cout << -ans << '\n';
		}
		else if (c == '<') {
			string s;
			ll x;
			cin >> s >> x;

			pre1->insert(s.c_str(), x);
			pre2->insert(s.c_str(), -x);
		}
		else {
			string s;
			ll x;
			cin >> s >> x;

			reverse(s.begin(), s.end());

			suf1->insert(s.c_str(), x);
			suf2->insert(s.c_str(), -x);
		}
	}
}