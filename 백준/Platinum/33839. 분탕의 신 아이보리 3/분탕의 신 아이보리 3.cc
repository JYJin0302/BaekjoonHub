#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve() {
	
	ll n, k;
	cin >> n >> k;
	k++;
	vector<ll> A(n);
	for(auto& i : A) cin >> i;

	if (n == 1){
		cout << A[0] << '\n' << 1 << ' '<< 1 << '\n';
		return;
	}

	ll tot = 0;
	for(auto f : A) tot += -f;

	vector<ll> sL(n);
	for(int i =0; i < n ;i++){
		sL[i] = A[i] + (i ? sL[i-1] : 0ll);
	}

	deque<pair<ll, int>> dq;
	dq.push_back(mp(0ll, -1));

	ll ans = 0;
	pair<int, int> adx = mp(1, 0);

	for(int i = 0; i < n; i++){
		while(!dq.empty() && dq.front().y < i - k) dq.pop_front();

		if (!dq.empty()){
			ll val = sL[i] - dq.front().x;
			if (val > ans) {
				ans = val;
				adx = mp(dq.front().y+1, i);
			}
			else if (val == ans){
				adx = min(adx, mp(dq.front().y+1, i));
			}
		}

		while(!dq.empty() &&dq.back().x > sL[i]) dq.pop_back();
		dq.push_back(mp(sL[i], i));
	}
	
	cout << tot + 2 * ans << '\n' << adx.x+1 << ' ' << adx.y+1 << '\n';


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	int t = 1;
 	//cin >> t;
	while (t--) { solve(); }
}