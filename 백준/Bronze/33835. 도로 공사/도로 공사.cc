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
	vector<pair<ll ,ll>> A(n);
	for(auto&[a,b]: A) cin >> a>> b;

	cout << fixed << setprecision(10);
	cout << sqrtl((A[n-1].x - A[0].x)*(A[n-1].x - A[0].x) + (A[n-1].y - A[0].y)*(A[n-1].y - A[0].y)) << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
 	//cin >> t;
	while (t--) { solve(); }
}