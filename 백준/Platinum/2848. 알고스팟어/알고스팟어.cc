#include <bits/stdc++.h>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n;
	cin >> n;

	vector<string>A(n);
	for (auto& i : A) cin >> i;

	vector<bool> used(26);
	vector<int> topo(26);

	for (string i : A) {
		for (auto k : i) used[k - 'a'] = 1;
	}

	vector<vector<int>> adj(26);
	for (int i = 1; i < n; i++) {

		string s1 = A[i - 1];
		string s2 = A[i];
        
        bool ok = 0;
		for (int j = 0; j < min(s1.size(), s2.size()); j++) {
			if (s1[j] != s2[j]) {
				adj[s1[j] - 'a'].push_back(s2[j] - 'a');
				topo[s2[j] - 'a']++;
                ok = 1;
				break;
			}
		}
        if (!ok && s1.size() > s2.size()) {
            cout << "!";
            return 0;
        }
	}

	queue<int> q;
	for (int i = 0; i < 26; i++) {
		if (used[i] && topo[i] == 0) q.push(i);
	}

	bool undefined = 0;

	string ans;
	while (!q.empty()) {

		if (q.size() != 1) {
			undefined = 1;
		}

		int a = q.front();
		q.pop();

		ans += a + 'a';
		for (int i : adj[a]) {
			topo[i]--;
			if (topo[i] == 0) q.push(i);
		}
	}

	int usedcnt = 0;
	for (int i = 0; i < 26; i++) usedcnt += used[i];

	if (ans.size() != usedcnt) cout << "!";
	else if (undefined) cout << "?";
	else cout << ans;

}