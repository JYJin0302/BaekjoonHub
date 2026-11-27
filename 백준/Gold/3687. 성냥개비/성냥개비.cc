#include <bits/stdc++.h>
using namespace std;

string dp[101];

bool cmp(string s1, string s2) {
	if (s1.size() < s2.size()) return 0;
	if (s1.size() > s2.size()) return 1;

	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] < s2[i]) return 0;
		if (s1[i] > s2[i]) return 1;
	}
}

void setDP() {
	string s = "";

	int digit[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };  // 0부터 9까지 필요한 성냥 개수
	
	dp[2] = "1";
	dp[3] = "7";
	dp[4] = "4";
	dp[5] = "2";
	dp[6] = "6";
	dp[7] = "8";
	dp[8] = "10";

	for (int i = 9; i <= 100; i++) {
		string t1 = "";
		for (int j = 0; j < 10; j++) {
			string t2 = dp[i - digit[j]] + (char)('0' + j);
			if (t1 == "" || cmp(t1, t2)) {
				t1 = t2;
			}
		}
		dp[i] = t1;
	}
}

void solve_max(int n) {
	if (n % 2 == 1) {
		cout << 7;
		n -= 3;
	}
	string s(n / 2, '1');
	cout << s;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	setDP();	

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		cout << dp[n];
		cout << ' ';
		solve_max(n);
		cout << '\n';
	}
}