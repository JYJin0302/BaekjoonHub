#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9+7;
vector<string> A;
ll f[3001];

ll ans = 1;

void solve(int l, int r, int ix) {
	if (l == r) return;
	//cout << l << ' ' << r << ' ' << ix << '\n';

	int cnt = 1;
	int pv = l;
	for (int i = l; i <= r; i++) {
		if (i!= l && (A[i-1].size() == ix || A[i][ix] != A[i - 1][ix])) {
			cnt++;
			solve(pv, i - 1, ix + 1);
			pv = i;
		}
	}
	
	//if (A[l].size() == ix) cnt--;
	ans = ans * f[cnt] % mod;
	solve(pv, r, ix + 1);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	f[0] = 1;
	for (int i = 1; i <= 3000; i++) f[i] = f[i - 1] * i % mod;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		A.push_back(s);
	}

	sort(A.begin(), A.end());

	ans = 1;
	solve(0, n - 1, 0);

	cout << ans;


}
