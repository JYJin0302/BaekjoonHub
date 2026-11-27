#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    int n;
    cin >> n;

    vector<int> A;
    for(int i =0 ; i< n ;i++){
        int x;
        cin >> x;

        A.push_back(x - i);
    }
    sort(all(A));

    int v =A[n/2];

    ll ans = 0;
    for(auto f : A){
        ans += abs(f - v);
    }
    cout << ans << '\n';
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
