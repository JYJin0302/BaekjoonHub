#include <bits/stdc++.h>
using namespace std;

string dp[31][500][30][30];  // 길이, 값, A개수, B개수

int main() {

	int n, k;
	cin >> n >> k;

	dp[1][0][1][0] = "A";
	dp[1][0][0][1] = "B";
	dp[1][0][0][0] = "C";

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {

			for (int a = 0; a <= i; a++) {
				for (int b = 0; a + b <= i; b++) {

					if (dp[i - 1][j][a][b] != "") {
						dp[i][j + a + b][a][b] = dp[i - 1][j][a][b] + 'C';
						dp[i][j][a + 1][b] = dp[i - 1][j][a][b] + 'A';
						dp[i][j + a][a][b + 1] = dp[i - 1][j][a][b] + 'B';
					}
                }
			}
		}
	}

	for (int a = 0; a <= n; a++) {
		for (int b = 0; a + b <= n; b++) {

			if (dp[n][k][a][b] != "") {
                cout << dp[n][k][a][b] << '\n';
                return 0;
            }

		}
	}
    
    cout << -1;
}