#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int V[200][2];
map<ll, int> idx;

int idxCnt;
int goSet(ll n){
	if (idx[n]) return idx[n];

	int L = goSet((n+1)/2);
	int R = goSet(n/2);

	idx[n] = ++idxCnt;
	V[idxCnt][0] = L;
	V[idxCnt][1] = R;
	return idxCnt;
}	

void solve() {

	ll n;
	cin >> n;

	for(int i = 1; i <= 130; i++) V[i][0] = V[i][1] = 0;

	idx.clear();
	
	idx[1] = 1;
	idxCnt = 1;
	int ans = goSet(n);

	cout << ans << '\n';
	for(int i = 1; i <= ans; i++){
		cout << V[i][0] - 1 << ' ' << V[i][1] - 1 << '\n';
	}
	cout << ans - 1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
 	cin >> t;
	while (t--) { solve(); }
}