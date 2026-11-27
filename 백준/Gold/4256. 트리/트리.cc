#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> p;

void post(int r) {
	if (p[r].first != 0) post(p[r].first);
	if (p[r].second != 0) post(p[r].second);
	cout << r << ' ';
}

int main() {

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		
		p = vector<pair<int, int>>(n + 1);

		vector<int> A(n), B(n);
		for (auto& i : A) cin >> i;
		for (auto& i : B) cin >> i;

		vector<int> idx(n + 1);
		for (int i = 0; i < n; i++) {
			idx[B[i]] = i;
		}

		int root = A[0];

		for (int i = 1; i < n; i++) {

			int f = root;
			while (1) {

				if (idx[f] > idx[A[i]]) {
					if (p[f].first == 0) break;
					f = p[f].first;
				}
				else {
					if (p[f].second == 0) break;
					f = p[f].second;
				}
			}

			if (idx[f] > idx[A[i]]) p[f].first = A[i];
			else p[f].second = A[i];
		}

		post(root);
		cout << '\n';
	}
}