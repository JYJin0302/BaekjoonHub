#include <bits/stdc++.h>
using namespace std;

vector<int> adj[51];
int topo[51];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<string> A(n);
	for (auto& i : A) cin >> i;

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (A[i][j] != A[j][i]) {
				if (A[i][j] == 'Y') {
					adj[i].push_back(j);
					topo[j]++;
				}
				else {
					adj[j].push_back(i);
					topo[i]++;
				}
			}
		}
	}


	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (topo[i] == 0) {
			q.push(i);
		}
	}

	int cnt = 0;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		cnt++;

		for (auto i : adj[a]) {
			topo[i]--;
			if (topo[i] == 0) q.push(i);
		}
	}

	if (cnt != n) cout << "NO";
	else cout << "YES";

}