#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using uint = unsigned int;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve(){

	int n;
	cin >> n;
	
	vector<pair<ll, ll>> A(n);
	for(auto& i :A ) cin >> i.x;
	for(int i =0 ; i < n; i++) A[i].y = i+1;

	sort(all(A));
	vector<ll> sA(n);
	for(int i =0 ; i < n; i++){
		sA[i] = A[i].x + (i ? sA[i-1] : 0);
	}

	ll ans = 0, ansi = 0;
	for(int i = 0; i < n;i++){
		ll val = sA[n-1] + A[n-1].x + 2*A[i].x - sA[i];

		if (val > ans){
			ans = val;
			ansi = i;
		}
	}

	cout << n - ansi << '\n';
	for(int i = ansi; i < n; i++){
		cout << A[i].y << ' ';
	}
	cout << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}