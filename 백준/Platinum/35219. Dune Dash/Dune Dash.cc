#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve() {
	int n;
	cin >> n;

	vector<pair<ll, ll>> A(n);
	for(auto&[a,b]:A) cin >> a>> b;

	int ix = 0;
	ll V = 0;
	for (int i = 1; i < n; i++) {
		ll tmp = (A[i].x - A[0].x) * (A[i].x - A[0].x) + (A[i].y - A[0].y) * (A[i].y - A[0].y);
		if (tmp > V){
			V = tmp;
			ix = i;
		}
	}

	vector<pair<ll, int>> B;
	for(int i = 0; i < n; i++){
		ll tmp = (A[i].x - A[ix].x) * (A[i].x - A[ix].x) + (A[i].y - A[ix].y) * (A[i].y - A[ix].y);
		B.push_back(mp(tmp, i));
	}
	sort(all(B));

	double ans = 0;
	for(int i = 1;i < n;i++){
		auto[a,b] = A[B[i].y];
		auto[c,d] = A[B[i-1].y];
		ll tmp = (a-c)*(a-c) + (b-d)*(b-d);
		ans += sqrtl(tmp);
	}
	cout << setprecision(15);
	cout << ans << '\n';

}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}