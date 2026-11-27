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

    vector<int> A(n);
    for(auto& i : A) cin >> i;

    int ans = 1;
    int cnt = 1;
    for(int i =1 ; i < n; i++){
        if (A[i] != A[i-1]) cnt++;
        else cnt = 1;
        ans =max(ans, cnt);
    }
    cout << ans << '\n';
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
