#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (auto& i : A) cin >> i;

	if (A[0] != 1) {
		cout << "NO\n";
		return;
	}
	vector<int> stk;
	for (auto f : A) {
		if (f == 1) {
			stk.push_back(1);
		} else {
			while (!stk.empty() && stk.back() != f - 1) stk.pop_back();
			if (stk.empty()) {
				cout << "NO\n";
				return;
			}
			stk.back()++;
		}
	}
	cout << "YES\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}