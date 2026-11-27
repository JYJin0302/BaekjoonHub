#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> primes(1004000);

	for (int i = 2; i < 1004000; i++) {
		if (primes[i] == -1) continue;
		primes[i] = 1;
		for (int j = i * 2; j < 1004000; j += i) {
			primes[j] = -1;
		}
	}

	vector<int> p_p;
	for (int i = 2; i < 1004000; i++) {
		if (primes[i] == 1) {
			string temp = to_string(i), temp2 = to_string(i);
			reverse(temp.begin(), temp.end());
			if (temp2 == temp) p_p.push_back(i);
		}
	}
	cout << *lower_bound(p_p.begin(), p_p.end(), n);
}