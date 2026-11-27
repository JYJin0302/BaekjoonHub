#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	string s1, s2;
	cin >> s1 >> s2;

	vector<int> cnt1(26), cnt2(26);
	for (auto f : s1) cnt1[f - 'a']++;
	for (auto f : s2) cnt2[f - 'a']++;

	for (int i = 0; i < 26; i++) {
		int v = max(cnt1[i], cnt2[i]);
		while (v--) cout << char('a' + i);
	}
	cout << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}