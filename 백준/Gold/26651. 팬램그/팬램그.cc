#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int x;
	cin >> x;

	cout << 'Z';

	int r = 30;
	while (r > 0) {

		r /= 2;
		int tx = (1 << r);
		int tv = x / tx;
		x %= tx;

		if (tv != 0) {
			cout << string(tv, 'A');
			for (int i = 1; i < 25; i++) cout << char('A' + i);
			cout << string(tx, 'Z');
		}

	}


}