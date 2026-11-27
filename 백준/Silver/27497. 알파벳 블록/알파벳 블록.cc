#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string G[9][9];

int dx[] = { 0, -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { 0, -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);


	int n;
	cin >> n;

	map<int, char> mp;

	int l = 0, r = 0;

	stack<int> oper;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		if (x == 3) {
			if (oper.empty()) continue;
			int y = oper.top();
			if (y == 2) {
				mp[l] = ' ';
				l++;
			}
			else {
				mp[r-1] = ' ';
				r--;
			}
			oper.pop();
		}
		else if (x == 1) {
			char c;
			cin >> c;
			mp[r] = c;
			r++;
			oper.push(x);
		}
		else {
			char c;
			cin >> c;
			mp[l - 1] = c;
			l--;
			oper.push(x);
		}
	}

	if (l == r) cout << 0;
	else {
		for (int i = l; i < r; i++) cout << mp[i];
	}
}