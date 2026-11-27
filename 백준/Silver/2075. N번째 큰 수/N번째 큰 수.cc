#include <bits/stdc++.h>
using namespace std;
#define INF 1000000009

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> A(n, vector<int>(n));

	for (int j = n-1; j >= 0; j--) {
		for (int i = 0; i < n; i++) {
			cin >> A[i][j];
		}
	}

	vector<int> ind(n);
	int ans = 0;
	for (int cnt = 0; cnt < n; cnt++) {
		int maxi = 0;
		int temp = -INF;
		for (int i = 0; i < n; i++) {
			if (A[i][ind[i]] > temp) {
				maxi = i;
				temp = A[i][ind[i]];
			}
		}
		ind[maxi]++;
		ans = temp;
	}

	cout << ans;
}