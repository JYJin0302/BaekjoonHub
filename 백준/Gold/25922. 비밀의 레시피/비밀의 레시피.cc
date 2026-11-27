#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;
string s;

int f(int l, int r) {

	int res = 0;
	for (int i = l; i < r; i++) {
		res = res * 10 + (s[i] - '0');
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	cout << "? 1000000000\n";
	cout.flush();
	
	cin >> s;

	vector<int> ans;
	int ix = s.size();
	while (ix > 0) {
		int lx = max(0, ix - 9);

		ans.push_back(f(lx, ix));
		ix = lx;
	}

	cout << "! ";
	for (auto i : ans) cout << i << ' ';
	cout << '\n';
	cout.flush();
}