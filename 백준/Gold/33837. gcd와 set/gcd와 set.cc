#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int gcd(int a, int b){
	if (a > b) swap(a, b);
	if (a == 0) return b;
	return gcd(b%a, a);
}
void solve() {
	
	int n;
	cin >> n;
	vector<int> A(n);
	for(auto& i : A) cin >> i;

	vector<int> cnt(5050);
	for(auto f : A) cnt[f] = 1;

	if(n == 1){
		cout << A[0] << '\n';
		return;
	}

	sort(all(A));
	A.erase(unique(all(A)), A.end());

	if(A[0] == A.back()){
		cout  << 2 * A[0] << '\n';
		return;
	}

	int ans = 0;
	int g = 0;
	for(auto f : A) if (f != A.back()) g = gcd(g, f);
	ans = A.back() + g;

	for(auto f : A){
		g = 0;
		for(auto k : A){
			if(k % f == 0) {}
			else g = gcd(g, k);
		}
		ans = max(ans, g + f);
		if(g == 0) ans = max(ans, f + A.back());
	}

	cout << ans << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
 	//cin >> t;
	while (t--) { solve(); }
}