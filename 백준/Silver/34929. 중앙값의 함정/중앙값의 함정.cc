#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){

    int n;
    cin >> n;
    
    vector<int> A(n);
    for(auto &i : A) cin >> i;
    sort(all(A));

    int ans = A[0];
    vector<array<int, 3>> res;
    for(int i = 2; i < n ;i+= 2){
        res.push_back({ans, A[i-1], A[i]});
        ans = A[i-1];
    }

    cout << ans << '\n';
    for(auto f : res) cout <<f[0] << ' ' << f[1] << ' ' << f[2] << '\n';

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}