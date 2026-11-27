#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, ix, sz;
ll dp[2200][2][2];
vector<ll> A;

ll solve(int x, int t, int dir) {
	// 위치, 차례, 방향 <->

	if (dp[x][t][dir] != -1e15) return dp[x][t][dir];
	if (x == 1) return dp[x][t][dir] = A[x];

	ll mv = 1e15, Mv = -1e15;
	if ((int)log2(x) == (int)log2(x-1) && dir == 0) {
		ll tmp = solve(x - 1, 1 - t, dir);
		mv = min(mv,tmp );
		Mv = max(Mv, tmp);
	}

	if ((int)log2(x) == (int)log2(x + 1) && dir == 1) {
		ll tmp = solve(x + 1, 1 - t, dir);
		mv = min(mv, tmp);
		Mv = max(Mv, tmp);
	}

	ll tmp = solve(x / 2, 1 - t, dir);
	ll tmp2 = solve(x / 2, 1 - t, 1 - dir);


	//if (x == 7 && dir == 0) cout << mv << ' ' << tmp << ' ' << tmp2 << '\n';
	if (t == 0) {
		tmp = max(tmp, tmp2);
		mv = min(mv, tmp);
		return dp[x][t][dir] = min(0ll, mv) + A[x];
	}

	tmp = min(tmp, tmp2);
	Mv = max(Mv, tmp);
	return dp[x][t][dir] = max(0ll, Mv) + A[x];

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	sz = pow(2, n) - 1;

	A = vector<ll> (sz+1);
	for (int i = 1; i <= sz; i++) cin >> A[i];

	for (int i = 0; i <= sz; i++) {
		dp[i][0][0] = -1e15;
		dp[i][0][1] = -1e15;
		dp[i][1][0] = -1e15;
		dp[i][1][1] = -1e15;
	}

	for (int i = 1; i <= sz; i++) {
		ll v1 = solve(i, 0, 0);
		ll v2 = solve(i, 0, 1);

		cout << min(v1, v2) << ' ';;
	}
}