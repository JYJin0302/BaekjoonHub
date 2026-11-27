#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using uint = unsigned int;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve(){

	ll a, b;
	cin >> a >> b;

	ll ta = a, tb = b;
	string sa, sb;
	while(ta){
		if (ta & 1) sa += '1';
		else sa += '0';
		ta >>= 1;
	}

	while(tb){
		if (tb & 1) sb += '1';
		else sb += '0';
		tb >>= 1;
	}

	reverse(all(sa)), reverse(all(sb));

	//cout << sa << '\n' << sb << '\n';

	if ((int)sa.size() != (int)sb.size()){
		cout << 0 << '\n';
		return;
	}
	
	int len = (int)sa.size();
	if (a == (1ll << len - 1) || b == (1ll << len - 1)){
		cout << 0 << '\n';
		return;
	}

	int ans = 1;
	int cnt0 = 0, cnt1 = 0;
	for(int i = 0 ; i < len; i++){
		if (sa[i] == sb[i]){
			if (sa[i] == '1') {
				ans += cnt0;
				cnt0 = 0;
			}
			else cnt0++;
		}
		else{
			bool ok = 1;
			for(int j = i+1; j < len ;j++){
				if (sa[j] == '1') ok = 0;
			}

			//cout << "OK: " << ok << '\n';
			if (ok) {}
			else ans += cnt0;
			break;
		}
	}
	cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}