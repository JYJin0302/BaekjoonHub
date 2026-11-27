#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int n, m, a;
	cin >> n >> m;

	map<string, int> si;
	map<int, string> is;

	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		is[i] = s;
		si[s] = i;
	}

	for (int i = 0; i < m; i++) {
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9') {
			a = stoi(s);
			cout << is[a] << '\n';
		}
		else {
			cout << si[s] << '\n';
		}
	}
}