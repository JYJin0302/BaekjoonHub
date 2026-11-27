#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 1e9+7;
ll fastPow(ll b, ll ex){
    ll res = 1;
    while(ex){
        if (ex&1) res = res* b % mod;
        b = b*b % mod;
        ex >>= 1;
    }
    return res;
}
ll f[505050];

void solve() {
    
    int n;
    cin >> n;
    
    int q;
    cin >> q;
    vector<pair<int, int>> A;

    map<int, int> cntL, cntR;

    bool ok = 1;
    while(q--){
        int a, b;
        cin >> a>> b;

        // a -> b , a <= b
        A.push_back(mp(a, b));
        cntL[a]++; if (cntL[a] >= 2) ok = 0;
        cntR[b]++; if (cntR[b] >= 2) ok = 0;
    }
    if (!ok) {
        cout << 0 << '\n';
        return;
    }
    
    sort(all(A));
    A.push_back(mp(n+1, n+1));
    
    vector<ll> res;
    ll pre = 0;
    for(auto[a,b] : A){
        if (a <= pre){
            cout << 0 << '\n';
            return;
        }


        ll nd = b - pre;
        if (a > pre + 1){
            res.push_back(1);
            nd--;
        }
        res.push_back(nd);
        pre = b;
    }

    ll ans = 1;
    ll tot = n+1;

    // cout << "RES: ";
    // for(auto f : res) cout << f << ' ';
    // cout << endl;
    reverse(all(res));
    for(auto v : res){
        ans = ans * f[tot - 1] % mod;
        ans = ans * fastPow(f[tot - v], mod-2) % mod;
        tot -= v;
    }
    cout << ans << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 

    f[0] = 1;
    for(int i =1; i <= 500000; i++){
        f[i] = f[i-1]* i % mod;
    }

    int t = 1;
    cin >> t;
    while (t--) solve();
}
