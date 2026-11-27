#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> A(n);
	for (auto& i : A) cin >> i;

	int ans = 0;
	for (int i = 1; i < n; i++) {
		ans += (A[i] + A[i - 1]) * (A[i] + A[i - 1]) + (A[i] - A[i - 1]) * (A[i] - A[i - 1]);
	}
	cout << ans;

}