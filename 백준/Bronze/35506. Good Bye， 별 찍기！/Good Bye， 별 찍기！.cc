#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

char G1[303][303];
char G2[303][303];

void solve() {
	int n;
	cin >> n;

	memset(G1, ' ', sizeof G1);
	memset(G2, ' ', sizeof G2);
	for (int i = 0; i < n * 2; i++) { G1[i][n * 2 - 1 - i] = '*'; }

	for (int i = 0; i < n; i++) {
		G2[i][n - 1 - i] = '*';
		G2[n * 2 - 1 - i][n - 1 - i] = '*';
		G2[i][n + i + 1] = '*';
		G2[n * 2 - 1 - i][n + i + 1] = '*';
	}

	for (int i = 0; i < n * 2; i++) {
		for (int j = 0; j < n * 2; j++) cout << G1[i][j];
		cout << ' ';
		for (int j = 0; j < n * 2 + 1; j++) cout << G2[i][j];
		cout << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}