#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) return a.second < b.second;

	return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {

		int n, m;
		cin >> n >> m;

		vector<pair<int, int>> A(m);
		for (auto& i : A) cin >> i.first >> i.second;

		sort(A.begin(), A.end(), cmp);

		int ans = 0;
		vector<bool> used(n + 1);
		for (auto i : A) {

			int a, b;
			tie(a, b) = i;

			for (int k = a; k <= b; k++) {
				if (!used[k]) {
					used[k] = 1;
					ans++;
					break;
				}
			}
		}

		cout << ans << '\n';
	}
}