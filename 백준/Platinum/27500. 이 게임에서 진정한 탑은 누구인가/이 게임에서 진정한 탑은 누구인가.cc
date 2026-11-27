#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool dp[303][301][301];
// dp[t][a][b] : 프레임 t 끝나고 잭스 체력 a 피오라 체력 b 상태
int f[303][301][301];
int fhp1[303][301][301];
int fhp2[303][301][301];

int st[320], dmg[320];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int hp1, hp2;
	cin >> hp1 >> hp2;

	int d1, d2, d3, d4;
	cin >> d1 >> d2 >> d3 >> d4;

	int m;
	cin >> m;
	for (int i = 0; i < 320; i++) st[i] = 1;

	for (int i = 0; i < m; i++) {
		int x;
		string s;
		cin >> x >> s;

		if (s[0] == 'a') {
			dmg[x + 4] = d3;
		}
		else {
			for (int j = 0; j < 9; j++) {
				st[x + j] = 0;
			}
			dmg[x + 9] = d4;
		}
	}

	int ansi = -1, h1 = 0, h2 = 0;

	f[0][hp1][hp2] = 1;
	dp[0][hp1][hp2] = 1;
	for (int i = 1; i <= 300; i++) {

		for (int a = 1; a <= hp1; a++) {
			for (int b = 1; b <= hp2; b++) {
				if (i >= 4) {
					bool ok = 0;
					if (i == 4 && a == hp1 && b == hp2) ok = 1;
					else if (i > 4 && dp[i - 5][a][b]) ok = 1;

					if (ok) {
						int inDmg = 0, outDmg = d1*st[i];
						for (int k = i - 4; k <= i; k++) inDmg += dmg[k];

						dp[i][max(0, a - inDmg)][max(0, b - outDmg)] = 1;
						f[i][max(0, a - inDmg)][max(0, b - outDmg)] = 5;
						fhp1[i][max(0, a - inDmg)][max(0, b - outDmg)] = a;
						fhp2[i][max(0, a - inDmg)][max(0, b - outDmg)] = b;
					}
				}

				if (i >= 14) {
					bool ok = 0;
					if (i == 14 && a == hp1 && b == hp2) ok = 1;
					if (i > 14 && dp[i - 15][a][b]) ok = 1;

					if (ok) {
						int inDmg = dmg[i], outDmg = d2 * st[i];
						dp[i][max(0, a - inDmg)][max(0, b - outDmg)] = 1;
						f[i][max(0, a - inDmg)][max(0, b - outDmg)] = 15;
						fhp1[i][max(0, a - inDmg)][max(0, b - outDmg)] = a;
						fhp2[i][max(0, a - inDmg)][max(0, b - outDmg)] = b;
					}
				}

				int inDmg = dmg[i];
				if (dp[i - 1][a][b]) {
					dp[i][max(0, a - inDmg)][b] = 1;
					f[i][max(0, a - inDmg)][b] = 1;
					fhp1[i][max(0, a - inDmg)][b] = a;
					fhp2[i][max(0, a - inDmg)][b] = b;
				}
			}
		}
	}

	for (int i = 0; i <= 300; i++) {
		for (int a = hp1; a > 0; a--) {
			if (dp[i][a][0]) {
				ansi = i;
				h1 = a;
				break;
			}
		}
		if (ansi != -1) break;
	}

	if (ansi == -1) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";

	vector<pair<int, string>> res;

	while (ansi >= 0) {
		int vf = f[ansi][h1][h2];

		if (vf == 5) {
			//cout << ansi - 4 << ' ' << "attack\n";
			res.push_back({ ansi - 4, "attack" });
		}
		else if (vf == 15) {
			//cout << ansi - 14 << ' ' << "counter strike\n";
			res.push_back({ ansi - 14, "counter strike" });
		}

		int th1 = fhp1[ansi][h1][h2];
		int th2 = fhp2[ansi][h1][h2];

		ansi -= vf;
		h1 = th1;
		h2 = th2;
	}

	reverse(res.begin(), res.end());
	for (auto i : res) {
		cout << i.first << ' ' << i.second << '\n';
	}

}