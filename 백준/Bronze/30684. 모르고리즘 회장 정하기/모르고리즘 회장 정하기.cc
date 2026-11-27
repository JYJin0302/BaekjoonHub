#include <iostream>
using namespace std;

bool chk[26][26][26];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.size() == 3) {
			chk[s[0] - 'A'][s[1] - 'A'][s[2] - 'A'] = 1;
		}
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			for (int k = 0; k < 26; k++) {
				if (chk[i][j][k]) {
					cout << char('A' + i) << char('A' + j) << char('A' + k);
					return 0;
				}
			}
		}
	}
	cout << "?";
	return 0;
}