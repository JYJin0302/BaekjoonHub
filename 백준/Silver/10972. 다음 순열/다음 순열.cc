#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	vector<int> A(n);
	for (auto& i : A) cin >> i;

	int ind = n-1;
	while (ind >= 1 && A[ind] < A[ind - 1]) ind--;
	ind--;
	if (ind < 0) cout << -1;
	else {
		vector<bool> check(n+1);
		for (int i = 0; i < ind; i++) {
			check[A[i]] = 1;
		}
		for (int i = ind; i < n; i++) {
			if (i == ind) {
				for (int k = A[i] + 1; k <= n; k++) {
					if (!check[k]) {
						check[k] = 1;
						A[ind] = k;
						break;
					}
				}
			}
			else {
				for (int k = 1; k <= n; k++) {
					if (!check[k]) {
						check[k] = 1;
						A[i] = k;
						break;					
					}
				}
			}
		}
		for (int i : A) cout << i << ' ';
	}
}