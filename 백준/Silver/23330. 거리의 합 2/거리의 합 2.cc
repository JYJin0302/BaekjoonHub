#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
    
    int n;
	cin >> n;

	vector<ll> A(n);
	for (auto& i : A) cin >> i;
	sort(A.begin(), A.end());

	ll ans = 0, curr = 0;
	for (int i = 0; i < n; i++) {
		ans += i * A[i] - curr;
		curr += A[i];
	}
	cout << ans*2;
}