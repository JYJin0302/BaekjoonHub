#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string G[9][9];

int dx[] = { 0, -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { 0, -1, 0, 1, -1, 1, -1, 0, 1 };

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, l;
	cin >> n >> l;
	vector<int> A(n);
	for (auto& i : A) cin >> i;

	for (int i = 1; i < n; i++) {
		A[i] += A[i - 1];
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int v = A[i];
		if (i >= l) v -= A[i - l];

		if (v >= 129 && v <= 138) cnt++;
	}
	cout << cnt;

}