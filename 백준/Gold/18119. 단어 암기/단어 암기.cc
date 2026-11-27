#include <bits/stdc++.h>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n, q;
	cin >> n >> q;

	vector<string> word;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		string temp(26, '0');
		for (char c : s) {
			temp[c - 'a'] = '1';
		}

		word.push_back(temp);
	}

	string curr(26, '1');
	vector<int> cnt(n);

	while (q--) {
		int k;
		char c;
		cin >> k >> c;

		if (k == 1) {
			curr[c - 'a'] = '0';
			for (int i = 0; i < n; i++) {
				if (word[i][c - 'a'] == '1')
					cnt[i]++;
			}
		}
		else {
			curr[c - 'a'] = '1';
			for (int i = 0; i < n; i++) {
				if (word[i][c - 'a'] == '1')
					cnt[i]--;
			}
		}

		int ret = 0;
		for (int i : cnt) {
			if (i == 0) ret++;
		}

		cout << ret << '\n';
	}
}