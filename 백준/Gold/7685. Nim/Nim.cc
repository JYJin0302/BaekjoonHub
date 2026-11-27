#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve(int n){

    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    int res = 0;
    for(auto f : A) res ^= f;

    if (!res){
        cout << 0 << '\n';
        return;
    }
    int ans = 0;
    for(auto f : A){
        if ((f ^ res) <= f) ans++;
    }
    cout << ans << '\n';
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
     cin >> t;
    while (t) {
        solve(t);
        cin >> t;
    }
}
