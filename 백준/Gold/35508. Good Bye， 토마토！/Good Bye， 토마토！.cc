#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	int n, d;
	cin >> n >> d;

	vector<array<int, 3>> A(n);
	for (int i = 0; i < n; i++) {
		int t, a, b;
		cin >> t >> a >> b;

		A[i] = {t, a, b};
	}
	vector<int> num = {0};
	for (int i = 0; i < n; i++) num.push_back(A[i][0]);
	sort(all(num));
	num.erase(unique(all(num)), num.end());

	int sn = (int)num.size();
	vector<int> pMax(sn);

	for (int i = 0; i < n; i++) {
		int ix = lower_bound(all(num), A[i][0]) - num.begin();
		pMax[ix] = max(pMax[ix], A[i][2]);
	}

	for(int i = 1; i < sn; i++){
		pMax[i] = max(pMax[i], pMax[i-1]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int curA = A[i][1];

		int rem = d - A[i][0];

		int ix = lower_bound(all(num), rem + 1) - num.begin() - 1;
		if (ix >= 0) { ans = max(ans, curA + max(pMax[ix], A[i][2])); }
	}
	cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}