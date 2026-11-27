#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);

	int n, m, a, b;
	cin >> n >> m;

	vector<vector<int>> A(n + 1, vector<int>(n + 1, INF));
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		A[a][b] = 1;
		A[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) A[i][i] = 0;


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
			}
		}
	}

	vector<int> ans(n + 1);
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) temp += A[i][j];
		ans[i] = temp;
	}

	int tar = *min_element(ans.begin()+1, ans.end());
	for (int i = 1; i <= n; i++) {
		if (ans[i] == tar) {
			cout << i;
			return 0;
		}
	}

}