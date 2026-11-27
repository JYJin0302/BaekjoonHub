#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, cnt = 0;
vector<int> A;

void mergeSort(int l, int r) {
	if (l == r) return;

	int m = (l + r) >> 1;
	mergeSort(l, m);
	mergeSort(m+1, r);

	vector<int> tmp;
	int ldx = l, rdx = m + 1;
	while (ldx <= m && rdx <= r) {
		if (A[ldx] <= A[rdx]) {
			tmp.push_back(A[ldx]);
			ldx++;
		}
		else {
			tmp.push_back(A[rdx]);
			rdx++;
		}
	}
	while (ldx <= m) {
		tmp.push_back(A[ldx]);
		ldx++;
	}
	while (rdx <= r) {
		tmp.push_back(A[rdx]);
		rdx++;
	}

	for (int i = l; i <= r; i++) {
		A[i] = tmp[i - l];
		cnt++;

		if (cnt == k) cout << A[i];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	A = vector<int>(n);
	for (auto& i : A) cin >> i;

	mergeSort(0, n - 1);
	
	if (cnt < k) cout << -1;

}