#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using uint = unsigned int;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string Grid[101];
bool used[101][101];
int ans[101][101];

bool inGrid(int x, int y){
	return x >= 0 && x < n && y >= 0&& y < m;
}


void solve(){
	
	cin >> n >> m;

	for(int i = 0; i < n; i++) cin >> Grid[i];

	for(int i = 0; i < n ;i++){
		for(int j = 0 ;j  < m;j ++){
			if(Grid[i][j] == '.') continue;

			int k = 1;

			while(1){
				bool ok = 1;
				for(int f = 0; f < 4; f++){
					int nx = i + dx[f] * k;
					int ny = j + dy[f] * k;
					if (inGrid(nx, ny) && Grid[nx][ny] == '*') {}
					else ok = 0;
				}

				if (ok) k++;
				else break;
			}

			ans[i][j] = k;
			if (k >= 2){
				for(int f = 0; f < 4; f++){
					for(int d= 0; d < k; d++){
						int nx = i + dx[f] * d;
						int ny = j + dy[f] * d;
						used[nx][ny] = 1;
					}
				}
			}
		}
	}


	vector<array<int, 3>> res;
	for(int i = 0; i < n; i++){
		for(int j =0;j  <m; j++){
			if(Grid[i][j] == '*' && !used[i][j]){
				cout << -1 << '\n';
				return;
			}

			if (Grid[i][j] == '*' && ans[i][j] >= 2){
				res.push_back({i + 1, j + 1, ans[i][j] - 1});
			}
		}
	}

	cout << (int)res.size() << '\n';
	for(auto f : res){
		cout << f[0] << ' ' << f[1] << ' ' << f[2] << '\n';
	}

	
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
