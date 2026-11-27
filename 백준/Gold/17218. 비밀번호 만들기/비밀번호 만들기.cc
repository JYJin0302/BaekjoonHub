#include <bits/stdc++.h>
using namespace std;

int main() {

	string s1, s2;
	cin >> s1 >> s2;

	vector<vector<int>> dp(s1.size()+1, vector<int> (s2.size()+1));

	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	vector<char> ans;

	int x = s1.size(), y = s2.size();
	int target = dp[x][y];
	while (1) {
		if (dp[x - 1][y] == target) x--;
		else if (dp[x][y - 1] == target) y--;
		else {
			ans.push_back(s1[x - 1]);
			x--;
			y--;
			target = dp[x][y];
			if (target == 0) break;
		}
	}

	for (auto i = ans.rbegin(); i != ans.rend(); i++) {
		cout << *i;
	}
}
