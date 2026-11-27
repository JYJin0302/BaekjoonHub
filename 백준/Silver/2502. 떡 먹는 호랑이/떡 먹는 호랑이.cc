#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int d, k;
	cin >> d >> k;

	vector<int> fib(d + 1);
	fib[0] = 1;
	fib[1] = 1;
	for (int i = 2; i <= d; i++) fib[i] = fib[i - 1] + fib[i - 2];

	int ma = fib[d - 3], mb = fib[d-2];
	// ma*x + mb * y = k

	for (int i = 1; i * ma <= k; i++) {
		if ((k - i * ma) % mb == 0) {
			cout << i << '\n' << (k - i * ma) / mb;
			return 0;
		}
	}
}