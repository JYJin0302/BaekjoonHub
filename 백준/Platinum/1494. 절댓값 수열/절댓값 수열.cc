#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ll search(ll val1, ll val2, ll idx){
	//cout << "go search: " << val1 << ' ' << val2 << ' '<< idx << '\n';
	if (idx < 10){
		vector<ll> tmp(10);
		tmp[0] = val1;
		tmp[1] = val2;
		for(int i =2; i <= idx; i++){
			tmp[i] = abs(tmp[i-1] - tmp[i-2]);
		}
		return tmp[idx];
	}

	if (val1 == 0){
		if (idx % 3 == 0) return 0;
		return val2;
	}
	if (val2 == 0){
		if (idx % 3 == 1) return 0;
		return val1;
	}
	if (val1 > val2){
		ll t = val1 / val2;

		ll nt = t + t / 2;
		if(idx >= nt + 1){
			idx -= nt;
			ll v1, v2;
			if(t & 1) v1 = val2, v2 = val1 % val2;
			else v1 = val1 % val2, v2 = val2;
			return search(v1, v2, idx);
		}

		t = (idx - 1) * 2 / 3;
		nt = t + t / 2;
		idx -= nt;
		ll v1, v2;
		if(t & 1) v1 = val2, v2 = val1 - val2 * t;
		else v1 = val1 - val2 * t, v2 = val2;
		return search(v1, v2, idx);
	}
	else{
		ll t = val2 / val1;
		ll nt = t + (t+1) / 2;
		if(idx >= nt + 1){
			idx -= nt;
			ll v1, v2;
			if(t & 1) v1 = val2 % val1, v2 = val1;
			else v1 = val1, v2 = val2 % val1;
			return search(v1, v2, idx);
		}

		t = (idx - 1) * 2 / 3;
		nt = t + (t+1) / 2;
		idx -= nt;
		ll v1, v2;
		if(t & 1) v1 = val2 - val1 * t, v2 = val1;
		else v1 = val1, v2 = val2 - val1 * t;
		return search(v1, v2, idx);
	}
}

void solve() {
	
	ll a, b;
	cin >> a >> b;

	int n;
	cin >> n;
	while(n--){

		ll x;
		cin >> x;
		cout << search(a, b, x) << '\n';
	}

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}