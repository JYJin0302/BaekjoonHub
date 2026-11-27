#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;


	int mv = 0, Mv = 0, val = 0;
	for (auto i : s) {
		if (i == '(') val++;
		else val--;
		mv = min(mv, val);
		Mv = max(Mv, val);

	}

	if (val != 0) cout << -1;
	else cout << max(-mv, Mv);

}