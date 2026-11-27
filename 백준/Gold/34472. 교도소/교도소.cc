#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve(){

    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i :A) cin >> i;

    ll tot = 0;
    for(auto f : A) tot += f;
    tot /= n;

    vector<ll> B(n);
    for(int i =0; i < n; i++){
        B[i] = A[i] - tot;
    }

    vector<ll> sB(n);
    for(int i = 0; i < n ;i++){
        sB[i] = B[i] + (i ? sB[i-1] : 0);
    }

    ll ans = 0;
    stack<pair<ll, ll>> stk;
    for(int i = 0; i < n; i++){
        if(B[i] > 0){
            stk.push(mp(B[i], i));
        }
        else if (B[i] < 0){
            ll val = -B[i];
            while(!stk.empty() && val && stk.top().x > 0){
                auto f = stk.top(); stk.pop();
                ll mn = min(f.x, val);
                f.x -= mn;
                val -= mn;
                ans += mn * (i - f.y);

                if (f.x) stk.push(f);
            }
            if (val) stk.push(mp(-val, i));
        }
    }

    while(!stk.empty()){
        auto[a,b] = stk.top(); stk.pop();

        if (a > 0) ans += a * (n - b);
        else ans += (-a) * b;

    }
    cout << ans << '\n';
    

}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}