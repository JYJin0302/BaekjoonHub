#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

void solve() {

    int n;
    cin >> n;
    
    int ans = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = i+2; j <= n; j++){
            for(int k = 2; k <= n; k += 2){
                if (i + j + k == n) ans++;
            }
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