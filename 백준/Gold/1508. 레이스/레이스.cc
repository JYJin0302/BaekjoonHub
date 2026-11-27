#include <bits/stdc++.h>
using namespace std;


int main() {

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> A(k);
	for (auto& i : A) cin >> i;

	int l = 1, r = n;
	string ans = "";

	while(l <= r){
	
		int mid = (l + r) / 2;

		string s(k, '0');
		s[0] = '1';
		
		int pre = A[0], cnt = 1;
		for (int i = 1; i < k; i++) {
			if (cnt == m) break;
			if (A[i] - pre >= mid) {
				cnt++;
				s[i] = '1';
				pre = A[i];
			}
		}

		if (cnt == m) {
			ans = s;
			l = mid + 1;
		}
		else r = mid - 1;

	}


	cout << ans;
}