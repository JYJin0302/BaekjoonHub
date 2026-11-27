#include <bits/stdc++.h>
using namespace std;

vector<int> root;

int find(int n) {
	if (n == root[n]) return n;

	return root[n] = find(root[n]);
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;

	root = vector<int>(n+2);

	vector<bool> card(n + 1);
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		card[a] = 1;
	}
	
	root[n + 1] = 0;
	for (int i = n; i >= 1; i--) {
		if (card[i]) root[i] = i;
		else root[i] = root[i + 1];
	}

	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;

		cout << find(a + 1) << '\n';
		root[find(a + 1)]++;
	}

}