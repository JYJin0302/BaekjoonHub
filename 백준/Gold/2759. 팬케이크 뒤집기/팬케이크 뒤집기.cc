#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int>A(n);
		for (auto& i : A) cin >> i;


		vector<int> ans;
		int cnt = 0;
		while(cnt < n) {
			int maxn = max_element(A.begin(), A.end() - cnt) - A.begin();

			if (maxn == n - 1 - cnt) ;
			else if (maxn == 0) {
				ans.push_back(n - cnt); reverse(A.begin(), A.end() - cnt);
			}
			else {
				ans.push_back(maxn + 1);
				reverse(A.begin(), A.begin() + maxn + 1);
				ans.push_back(n - cnt);
				reverse(A.begin(), A.end() - cnt);
			}
			cnt++;
		}

		cout << ans.size() << ' ';
		for (int i : ans) cout << i << ' ';
		cout << '\n';
	}


}