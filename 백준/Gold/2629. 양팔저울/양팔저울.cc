#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n;
	vector<int> w(n);
	for (auto& i : w) cin >> i;
	cin >> k;
	vector<int> t(k);
	for (auto& i : t) cin >> i;

	vector<bool> dp(15001); // 15000: 0
	vector<int> temp;

	for (int i : w) {
		
		for (int j = 0; j <= 15000; j++) {
			if (dp[j] == 1) {
				if (j + i <= 15000) temp.push_back(i+j);
				temp.push_back(abs(i - j));
			}
		}
		temp.push_back(i);
		for (int i : temp) dp[i] = 1;
		temp.clear();
	}
	for (int i : t) {
		if (i > 15000) cout << "N ";
		else cout << (dp[i] ? "Y " : "N ");
	}
}