#include <bits/stdc++.h>
using namespace std;


int main() {
ios::sync_with_stdio(false);
cin.tie(0);
	int n;
	cin >> n;

	priority_queue<int, vector<int>, less<int>> L;
	priority_queue<int, vector<int>, greater<int>> R;

	L.push(-1000000);
	R.push(1000000);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		int l = L.top(), r = R.top();
		if (x > r) {
			R.push(x);
			
			if (R.size() > L.size()) {
				R.pop();
				L.push(r);
			}
		}
		else if (x >= l) {
			if (L.size() > R.size()) R.push(x);
			else L.push(x);
		}
		else {
			L.push(x);
			if (L.size() > R.size() + 1) {
				L.pop();
				R.push(l);
			}
		}

		cout << L.top() << '\n';
	}
}