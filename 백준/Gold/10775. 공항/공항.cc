#include <bits/stdc++.h>
using namespace std;

vector<int> root;

int find(int n) {
	if (n == root[n]) return n;

	return root[n] = find(root[n]);
}

int main() {

	int g, p;
	cin >> g >> p;

	root = vector<int>(g+1);

	for (int i = 1; i <= g; i++) root[i] = i;

	int cnt = 0;
	for (int i = 0; i < p; i++) {
		int k;
		cin >> k;

		if (find(k) != 0) {
			cnt++;
			root[find(root[k])]--;
		}
		else break;
	}

	cout << cnt;
}