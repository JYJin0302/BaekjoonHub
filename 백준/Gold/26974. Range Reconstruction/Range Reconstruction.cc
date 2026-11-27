#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int A[301][301];

vector<int> ans;

bool ck(int ix, int num) {
	int mx = num, Mx = num;

	for (int i = ix - 1; i >= 0; i--) {
		mx = min(mx, ans[i]);
		Mx = max(Mx, ans[i]);

		if (Mx - mx != A[i][ix]) return 0;
	}
	return 1;

}

void solve() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cin >> A[i][j];
		}
	}
	ans = vector<int>(n);
	ans[1] = A[0][1];

	int mv = 0, Mv = ans[1];
	for (int i = 2; i < n; i++) {
		
		int nv = A[i - 1][i];

		int v1 = nv + ans[i - 1];
		bool ok = ck(i, v1);

		if (ok) ans[i] = v1;
		else ans[i] = ans[i - 1] - nv;

	}

	for (auto i : ans) cout << i << ' ';

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.flush();

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}

}