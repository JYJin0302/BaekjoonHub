#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main() {
	ull m, n, a, b;
	cin >> m >> n;

	ull sum = 0;
	vector<ull> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		sum += A[i];
	}
    
    sort(A.begin(), A.end());

	ull ans = 0;
	ull target = sum - m;
	for (ull i : A) {
		if (i < target / n) {
			ans += i * i;
			target -= i;
		}
		else {
			ans += (target / n) * (target / n);
			target -= target / n;
		}
		n--;
		
	}
	cout << ans;
}