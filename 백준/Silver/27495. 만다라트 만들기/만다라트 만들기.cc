#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string G[9][9];

int dx[] = { 0, -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { 0, -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<string>> A(8);

	for (int i = 0; i < 9; i++ ) {
		for (int j = 0; j < 9; j++) {
			cin >> G[i][j];
		}
	}

	int cnt = 0;
	for (int i = 1; i < 9; i += 3) {
		for (int j = 1; j < 9; j += 3) {
			if (i == 4 && j == 4) continue;

			for (int k = 0; k < 9; k++) {
				int ni = i + dx[k];
				int nj = j + dy[k];

				A[cnt].push_back(G[ni][nj]);
			}
			cnt++;
		}
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < 8; i++) {
		cout << "#" << i+1 << ". ";
		cout << A[i][0] << '\n';

		vector<string> tmp;
		for (int j = 1; j < 9; j++) {
			tmp.push_back(A[i][j]);
		}
		sort(tmp.begin(), tmp.end());

		for (int j = 0; j < 8; j++) {
			cout << "#" << i+1 << "-" << j + 1 << ". " << tmp[j] << '\n';
		}
	}

}