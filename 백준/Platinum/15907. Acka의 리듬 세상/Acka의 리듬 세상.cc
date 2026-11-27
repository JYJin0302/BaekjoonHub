#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

bool isP[2002020];
int cnt[2002020];

void solve() {
	
	int n;
	cin >> n;
	vector<int> A(n);
	for(auto& i : A) cin >> i;

	vector<int> p;
	for(int i = 2; i <= 1000000; i++){
		if(isP[i]) continue;
		p.push_back(i);
		for(int j = i*2; j <= 1000000;j += i) isP[j] = 1;
	}

	int ans = min(n, 2);
	for(auto f : p){
		//cout << "TEST: " << f << '\n';
		int res = 0;
		for(auto a : A){
			res = max(res, ++cnt[a % f]);
		}
		ans = max(ans, res);
        for(auto a : A){
			cnt[a % f] = 0;
		}
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