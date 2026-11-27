#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};


ll getCnt(ll x, ll y) {
	x = abs(x), y = abs(y);
	if (x < y) swap(x, y);

	if (x == 1 && y == 0) return 3;
	if (x == 2 && y == 2) return 4;

	ll v1 = (x + 1) / 2;
	ll v2 = (x + y + 2) / 3;
	ll res = max(v1, v2);
	if ((res + x + y) & 1) res++;
	return res;
}
void solve() {

	ll x, y;
	cin >> x >> y;
	x = abs(x), y =abs(y);
	if(x < y)swap(x, y);

	if(x + y == 0 || (x == 2 && y == 1)){
		cout << -1 << '\n';
		return;
	}

	vector<int> res;
	for(int i =0 ;i < 8 ;i++){
		ll nx = x - dx[i];
		ll ny = y - dy[i];

		res.push_back(getCnt(nx, ny));
	}
	sort(all(res));

	int cnt = 0;
	for(int i =0 ;i < 8; i++){
		if (res[i] == res[0]) cnt++;
	}
	cout << cnt << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int t = 1;
	cin >> t;
	while (t--) { solve(); }
	return 0;
}