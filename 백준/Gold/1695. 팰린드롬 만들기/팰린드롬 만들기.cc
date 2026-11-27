#include <bits/stdc++.h>
using namespace std;

vector<int> A;
vector<vector<int>> s;
int dp(int l, int r) {
	
	if (l >= r) return 0;
	if (s[l][r] != -1) return s[l][r];
    
	if (A[l] == A[r]) return s[l][r] = dp(l + 1, r - 1);
	return s[l][r] = min(dp(l, r - 1), dp(l + 1, r)) + 1;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	A = vector<int>(n);
	s = vector<vector<int>>(n, vector<int>(n, -1));
	for (auto& i : A)cin >> i;

	cout << dp(0, n - 1);
}