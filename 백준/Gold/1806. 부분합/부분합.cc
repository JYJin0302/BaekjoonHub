#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, s;
	cin >> n >> s;

	vector<int> A(n);
	for (auto& i : A) cin >> i;

	int l = 0, r = 0;
	int sum = 0;
	int ans = 0;
	while (r < n) {
		sum += A[r];
		if (sum >= s) {
			while (sum >= s) sum -= A[l++];
			if (ans == 0) ans = r - l+2;
			else ans = min(ans, r - l+2);
			
		}
		r++;
	}
	cout << ans;
}