#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int l = 0,r = 0;
    vector<int> Z(n);
    for(int i = 1; i < n; i++){
        if(i < r) Z[i] = min(r-i+1, Z[i-l]);
        while(i + Z[i]< n && s[Z[i]] == s[i+Z[i]]) Z[i]++;
        if (i + Z[i] - 1 > r){
            l = i, r = i + Z[i] - 1;
        }
    }
    
    if (k >= n){
        cout << n << '\n';
        return;
    }

    for(int i = n-1; i >= 1; i--){
        if (i + Z[i] < n) continue;
        int nd = (n + i -1) / i * i - n;
        if(nd <= k) {
            cout << i << '\n';
            return;
        }
    }
    cout << 0 << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
   // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
