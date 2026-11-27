#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

const int mod = 1e9 + 7;

void solve(){
    
    ll n, d;
    cin >> n >> d;
    int a, b;
    cin >> a>> b;
    vector<ll> A(n);
    for(auto& i : A) cin >> i;

    ll dif = a - b;
    sort(all(A));
    reverse(all(A));
    // 첫 a 개 중에서 가장 작은 d개만 +1 되는 효과

    ll L = 0, R = 1e10;
    while(L <= R){
        ll md = ( L+R)>>1;
       // cout << "Go: " << md << endl;

        vector<ll> T(a);
        ll tot = 0;
        for(int i = 0; i < a;i++){
            if(A[i] >= md) T[i] = A[i];
            else{
                ll add = min(d, md - A[i]);
                T[i] = A[i] + add;
                tot += add;
            }
        }

        // adjust excess
        int ix = 0;
        while(ix < a && T[ix] != md) ix++;
        int nx = ix;
        while(nx < a && T[nx] == md) nx++;

        int len = nx - ix;
        ll exx = tot - d * dif;

        // cout << exx << ' ' << len << '\n';
        // for(auto f: T) cout << f<< ' ';
        // cout << '\n';
        if(exx >= len){
            R = md - 1;
            continue;
        }
        if (exx < 0){
            L = md + 1;
            continue;
        }

        while(exx){
            nx--;
            T[nx]--;
            exx--;
        }
        
        ll ans = 0;
        for(int i =0 ; i< a; i++) (ans += T[i] * T[i] % mod) %= mod;
        for(int i = a; i < n; i++) (ans += A[i] * A[i] % mod) %= mod;
        
        cout << ans << '\n';
        break;
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
