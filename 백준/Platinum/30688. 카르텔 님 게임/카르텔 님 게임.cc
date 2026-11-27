#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	bool ok = 1;
	if (n <= k) ok = 1;
	else if (n <= k + 2) ok = 0;
	else if (n <= 2 * k + 1) ok = 1;
	else ok = 0;

	if (ok) cout << "A and B win";
	else cout << "C win";

	return 0;
}