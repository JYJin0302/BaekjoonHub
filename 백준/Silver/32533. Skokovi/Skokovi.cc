#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
 
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for(auto& i : A) cin >> i;
    
    ll l = A[0] - k, r = A[0] + k;
    for(int i =0 ; i< n;i++){
        if(l <= A[i] && A[i] <= r) {
            cout << 1 << ' ';
            r = max(r, A[i] + k);
            l = min(l, A[i] - k);
        }
        else cout << 0 << ' ';

    }
    cout << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int t = 1;
   // cin >> t;
    for(int i =0 ;i < t;i ++){
        solve();
    }


    return 0;
}