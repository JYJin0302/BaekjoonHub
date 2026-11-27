#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll ,ll> dp[1000000];  // dp[i]: 답이 i인 구간 = first <= ... <= second

int main() {
	ll n;
	cin >> n;

	dp[1] = { 1, 1 };

	int curr = 2;
	ll ind = 2;
	while (1) {
		
		dp[ind] = { dp[ind - 1].second + 1, dp[ind - 1].second + curr };
		if (dp[ind].second >= n) break;
		ind++;
		if (dp[curr].second < ind) curr++;
	}

	if (n == 1) cout << 1;
	else cout << ind;
}