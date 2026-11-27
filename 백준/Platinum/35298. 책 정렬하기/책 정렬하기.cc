#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int cur[101];
int tmp[101];

int n;
vector<int> ans;
void oper(int ix) {
	if (ix < 0) exit(0);
	ans.push_back(ix + 1);

	int tx = 2;
	for (int j = 0; j < n; j++) {
		if (j == ix) {
			tmp[j] = cur[0];
			tmp[j + 1] = cur[1];
			j++;
		} else {
			tmp[j] = cur[tx++];
		}
	}
	for (int j = 0; j < n; j++) cur[j] = tmp[j];

	// cout << "Oper: " << ix << " | ";
	// for (int j = 0; j < n; j++) cout << cur[j] << ' ';
	// cout << endl;
}

void solve() {
	cin >> n;

	vector<int> A(n);
	for (auto& i : A) cin >> i;

	for (int i = 0; i < n; i++) cur[i] = i + 1;
	int ix = n - 1;
	while (ix >= 0) {
		while (ix >= 0 && A[ix] == cur[ix]) ix--;
		if (ix < 0) break;
		if (ix == 1) {
			cout << "NO\n";
			return;
		}

		int tar = A[ix];
		while (1) {
			if (cur[0] != tar && cur[1] != tar) oper(ix - 1);
			else if (cur[0] == tar) {
				oper(1);
			} else {
				oper(ix - 1);
				break;
			}
		}
	}

	cout << "YES\n";
	cout << (int)ans.size() << '\n';
	reverse(all(ans));
	for (auto f : ans) cout << f << ' ';
	cout << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}