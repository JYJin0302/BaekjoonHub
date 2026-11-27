#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	int n;
	cin >> n;
	vector<string> A(n);
	for (auto& i : A) cin >> i;

	vector<int> cnt(26);
	for (auto f : A) { cnt[f[0] - 'a']++; }

	string ans;
	for (int i = 0; i < 26; i++) {
		if (cnt[i] >= 5) ans += char('a' + i);
	}
	if (ans.empty()) cout << "PREDAJA\n";
	else cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}