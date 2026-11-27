#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define pii pair<ll, ll>


void solve() {

    int n, m;
    cin >> n >> m;
    vector<string> A(n);
    for(auto& i : A) cin >> i;
    
    vector<bool> chk(m);
    for(auto f : A){
        for(int j = 0; j < m; j++){
            if (f[j] == 'O') chk[j] = 1;
        }
    }
    
    for(int i = 0; i < m; i++){
        if (!chk[i]){
            cout << i+1;
            return;
        }
    }
    cout << "ESCAPE FAILED\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}