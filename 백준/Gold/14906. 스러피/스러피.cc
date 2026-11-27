#include <bits/stdc++.h>
using namespace std;

string s;

bool isSlump(int l, int r) {

	if (s[r] != 'G') return 0;
	int indF = -1;
	
	int i = l + 1;
	if (s[i] != 'F') return 0;
		
	while (i <= r && s[i] == 'F') i++;
	if (i <= r) indF = i;
	else return 0;

	return (s[l] == 'D' || s[l] == 'E') && (indF == r || isSlump(indF, r));
}

bool isSlimp(int l, int r) {
	if (l >= r) return 0;
	if (s[l] != 'A') return 0;

	if (r == l + 1) {
		return s[r] == 'H';
	}

	if (s[r] != 'C') return 0;
	if (s[l + 1] == 'B') return isSlimp(l+2, r-1);
	return isSlump(l + 1, r - 1);
}

bool isSlurpy(int l, int r) {

	int ind = -1;
	for (int i = r - 1; i >= l; i--) {
		if (s[i] == 'C' || s[i] == 'H') {
			ind = i;
			break;
		}
	}

	return isSlimp(l, ind) && isSlump(ind + 1, r);
}





int main() {

	int n;
	cin >> n;

	cout << "SLURPYS OUTPUT\n";
	for (int i = 0; i < n; i++) {

		cin >> s;

		if (isSlurpy(0, s.size() - 1)) cout << "YES\n";
		else cout << "NO\n";
	}
	cout << "END OF OUTPUT";
}