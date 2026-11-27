#include <bits/stdc++.h>
using namespace std;
#define INF 600000

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	vector<vector<int>> path(5, vector<int>(5, INF));

	int n;
	cin >> n;
	if (n == 0) {
		cout << 0; return 0;
	}
	path[0][n] = 2;
	path[n][0] = 2;

	cin >> n;
	while (n != 0) {
		vector<vector<int>> temp(5, vector<int>(5, INF));

		for (int a = 0; a < 5; a++) {
			for (int b = a + 1; b < 5; b++) {
				if (b == n) temp[a][n] = min(temp[a][n], path[a][b] + 1);
				else if (abs(b - n) == 2) temp[a][n] = min(temp[a][n], path[a][b] + 4);
				else temp[a][n] = min(temp[a][n], path[a][b] + 3);

				temp[n][a] = temp[a][n];

				if (a == 0) temp[b][n] = min(temp[b][n], path[b][a] + 2);
				else if (a == n) temp[b][n] = min(temp[b][n], path[b][a] + 1);
				else if (abs(a - n) == 2) temp[b][n] = min(temp[b][n], path[b][a] + 4);
				else temp[b][n] = min(temp[b][n], path[b][a] + 3);

				temp[n][b] = temp[b][n];
			}
		}

		swap(path, temp);
		cin >> n;
	}

	int ans = INF;
	for (int i = 0; i < 5; i++) {
		for (int j = i + 1; j < 5; j++) {
			ans = min(ans, path[i][j]);
		}
	}
	
	cout << ans;

}