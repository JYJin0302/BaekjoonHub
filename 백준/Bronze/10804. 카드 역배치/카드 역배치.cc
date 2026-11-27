#include <bits/stdc++.h>
using namespace std;


int main() {

	vector<int> A(20);
	for (int i = 0; i < 20; i++) A[i] = i + 1;
	for (int i = 0; i < 10; i++) {
		int l, r; 
		cin >> l >> r;
		l--, r--;

		while (l < r) {
			swap(A[l], A[r]);
			l++, r--;
		}
	}

	for (auto f : A) cout << f << ' ';
}