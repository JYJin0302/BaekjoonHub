#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> adj[5001];
vector<int> rev[5001];

int n, m;
int maxVal[5001], minVal[5001];

bool reg_cnt[5001][5001], rev_cnt[5001][5001];
bool visited[5001];

void dfs(int v, int pv = -1) {
    if (visited[v]) return;
    visited[v] = 1;
	reg_cnt[v][v] = 1;
	for (int i : adj[v]) if (i != pv) {
		if (!visited[i]) dfs(i, v);

		for (int j = 0; j < n; j++) reg_cnt[v][j] |= reg_cnt[i][j];
	}
}

void dfs2(int v, int pv = -1) {
    if(visited[v]) return;
    visited[v] = 1;
    
	rev_cnt[v][v] = 1;
	for (int i : rev[v]) if (i != pv) {
		if (!visited[i]) dfs2(i, v);

		for (int j = 0; j < n; j++) rev_cnt[v][j] |= rev_cnt[i][j];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	cin >> n >> m;

	while (m--) {

		int x, y;
		cin >> x >> y;

		adj[x].push_back(y);
		rev[y].push_back(x);
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	
	for(int i = 0; i < n; i++) visited[i] = 0;
	for(int i = 0; i < n; i++){
	    if(!visited[i]){
	        dfs2(i);
	    }
	}

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (rev_cnt[i][j]) cnt++;
		}
		minVal[i] = cnt - 1;
		cnt = n;
		for (int j = 0; j < n; j++) {
			if (reg_cnt[i][j]) cnt--;
		}
		maxVal[i] = cnt;

		//cout << minVal[i] << ' ' << maxVal[i] << '\n';
	}

	int ans1 = 0, ans2 = 0, ans3 = 0;
	for (int i = 0; i < n; i++) {
		if (maxVal[i] < a) ans1++;
		if (maxVal[i] < b) ans2++;
		if (minVal[i] >= b) ans3++;
	}

	cout << ans1 << '\n' << ans2 << '\n' << ans3;

}