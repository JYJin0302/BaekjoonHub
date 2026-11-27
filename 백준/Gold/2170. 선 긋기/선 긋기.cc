#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, a, b, ans = 0;
	cin >> n;

	vector<pair<ll, ll>> A;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		A.push_back({ min(a, b), max(a, b) });
	}
    
    sort(A.begin(), A.end());
	ll l = 0, r = 0;
	for (int i = 0; i < n; i++){
		tie(a, b) = A[i];
		if (i == 0) l = a, r = b;
		else {
			if (r >= a) r = max(r, b);
			else {
				ans += r - l;
				l = a, r = b;
			}
		}
		
	}
	ans += r - l;
	cout << ans;
}