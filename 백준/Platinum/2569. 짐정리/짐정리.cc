#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, a, ans, temp, cnt;
vector<bool> check;
vector<pair<ll, ll>> A;

void dfs(ll v, ll plus) {
	cnt++;
	check[v] = 1;
	if (A[v].first == plus) return;

	temp += plus + A[v].first;

	if (!check[A[v].second]) dfs(A[v].second, plus);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	ll minn = 1000001;

	A = vector<pair<ll, ll>>(n);
	for (int i = 0; i < n; i++) {
		cin >> a;
		minn = min(minn, a);
		A[i] = { a, i };
	}

	ans = 0;
	check = vector<bool>(n);

	sort(A.begin(), A.end());

	for (int i = 0; i < n; i++) {
		if (check[i]) continue;
		check[i] = 1;
		temp = 0;
		cnt = 0;
		if (!check[A[i].second]) {
			dfs(A[i].second, A[i].first);
		}
		temp += min(0ll, (A[i].first * (2ll - cnt) + minn * (cnt + 2ll)));
		ans += temp;
	}
	cout << ans;
}