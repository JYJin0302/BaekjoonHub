#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	ll n;
	cin >> n;
	while(n){
		ll i;
		for (i = (sqrt(8 * n) - 1)/2 + 1; i>= 1; i--) {
			if ((i % 2 == 1 && n % i == 0) || (i % 2 ==0 && n / i * i + i/2 == n)) {

				if (i % 2 == 0) {
					cout << n / i - i / 2 + 1 << ' ' << i << '\n';
				}
				else {
					cout << n / i - i / 2 << ' ' << i << '\n';
				}
				break;
			}
		}

		cin >> n;
	}
}