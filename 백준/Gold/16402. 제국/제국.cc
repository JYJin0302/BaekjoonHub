#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> root;

int find(int n) {
	if (root[n] == n) return n;
	return root[n] = find(root[n]);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	root = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) root[i] = i;

	string s;
	getline(cin, s);

	vector<string> Name(n + 1);
	map<string, int> ind;

	for (int i = 1; i <= n; i++) {
		
		getline(cin, s);
		s = s.substr(11, 20);

		Name[i] = s;
		ind[s] = i;
	}

	for (int i = 0; i < m; i++) {
		getline(cin, s);

		string s1, s2;
		int t = 11;
		while (s[t] != ',') s1 += s[t], t++;

		t += 12;
		while (s[t] != ',') s2 += s[t], t++;

		t++;
		int x = s[t] - '0';

		int x1, x2;
		x1 = ind[s1], x2 = ind[s2];

		bool rebel = (find(x1) == find(x2));

		if (x == 2) swap(x1, x2);

		root[root[x2]] = x1;

		if (rebel) root[x1] = x1;
	}
	
	vector<string> ans;
	for (int i = 1; i <= n; i++) {
		find(i);
		if (root[i] == i) {
			ans.push_back(Name[i]);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout << "Kingdom of " << i << '\n';
	}

}