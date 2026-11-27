#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };



void solve() {
    
    int n, m;
    cin >> n >> m;
    
    vector<int> A(n);
    for(auto&i : A) cin >> i;
    
    int l = 0, r = 0;
    int ans = 0;
    int temp = 0;
    while(l < n && r < n){
        while(r < n && temp <= m){
            temp += A[r++];
            if (temp == m) ans++;
        }
        
        while(l < r && temp >= m){
            temp -= A[l++];
            if (temp == m) ans++;
        }
    }
    
    cout << ans;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 1;
	//cin >> T;

	while (T--) {
		solve();
	}
}