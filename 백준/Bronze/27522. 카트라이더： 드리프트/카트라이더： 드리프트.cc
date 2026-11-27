#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<pair<string, int>> C(8);

	for (int i = 0; i < 8; i++) {
		string s;
		cin >> s;

		char c;
		cin >> c;

		if (c == 'R') C[i] = { s, 0 };
		else C[i] = { s, 1 };
	}

	sort(C.begin(), C.end());

	vector<int> score = { 10, 8, 6, 5, 4, 3, 2, 1 };

	vector<int> res(2);
	for (int i = 0; i < 8; i++) {
		res[C[i].second] += score[i];
	}

	if (res[0] > res[1]) cout << "Red";
	else cout << "Blue";
}