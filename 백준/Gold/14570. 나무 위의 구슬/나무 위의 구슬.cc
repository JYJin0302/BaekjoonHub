#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	vector<pair<int, int>> A(n + 1);

	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		A[i] = { a, b };
	}
	ll k;
	cin >> k;
	k--;

	string bin;
	ll t = 1;

	while (k > 0) {
		char c = k % 2 + '0';
		bin += c;
		k /= 2;
	}
	while (bin.size() < 60) bin += '0';

	int ind = 0, node = 1;
	int a, b;
	tie(a, b) = A[node];
	while (!(a == -1 && b == -1)) {
		if (a == -1) node = b;
		else if (b == -1) node = a;
		else {
			if (bin[ind] == '0') node = a;
			else node = b;
			ind++;
		}

		tie(a, b) = A[node];
	}

	cout << node;
}
