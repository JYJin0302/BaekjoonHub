#include <bits/stdc++.h>
using namespace std;

int n, r1, r2;
vector<vector<pair<int, int>>> base;
vector<int> path;
vector<bool> check;
bool found;

void dfs(int v, int p = 0) {
	check[v] = 1;

	for (auto i : base[v]) {
		int a, b;
		tie(a, b) = i;
		if (a != v && !check[a]) {
			if (a == r2) {
				found = true;
				path.push_back(b);
				return;
			}
			dfs(a, v);
			if (found) {
			path.push_back(b);
			return;
			}
		}
		
	}
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	cin >> n >> r1 >> r2;
	base = vector<vector<pair<int, int>>>(n + 1);
	check = vector<bool>(n + 1);
	found = false;
    
    int a, b, c;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		base[a].push_back({ b, c });
		base[b].push_back({ a, c });
	}
    if (r1 == r2) {
        cout << 0;
        return 0;
    }
	dfs(r1);
	
	int ans = 0;
	path.erase(max_element(path.begin(), path.end()));
	for (int i : path) ans += i;
	cout << ans;
}