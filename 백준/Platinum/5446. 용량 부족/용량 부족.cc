#include <bits/stdc++.h>
using namespace std;

struct Node {
	bool del = 1, isend = 0;
	map<char, Node> child;
}root;

void insert(Node& n, string s, bool type, int i = 0) {

	n.del = type;
	if (i == s.size()) {
		if (type) n.isend = 1;
		return;
	}

	insert(n.child[s[i]], s, type, i+1);
}

int ans;
void solve(Node& n) {

	if (n.del == 1) {
		ans++;
		return;
	}

	if (n.isend) ans++;

	for (auto it = n.child.begin(); it != n.child.end(); it++) {
		solve(it->second);
	}
}

int main() {

	
	int t;
	cin >> t;
	while (t--) {

		root = Node();

		int n, m;
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;

			insert(root, s, 1);
		}

		cin >> m;
		for (int i = 0; i < m; i++) {
			string s;
			cin >> s;

			insert(root, s, 0);
		}

		ans = 0;
		solve(root);
		cout << ans << '\n';
	}
}