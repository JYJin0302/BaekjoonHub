#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int p2 = 1000003;

int A[1010][505];

void solve(){
    
    int n, m;
    cin >> n >> m;

    for(int i =0 ; i < n*2; i++){
        string s;
        cin >> s;
        for(int j =0 ; j <m ;j++){
            int ret = 0;
            if (s[j] == 'A') ret = 0;
            else if (s[j] == 'C') ret = 1;
            else if (s[j] == 'G') ret = 2;
            else ret = 3;
            A[i][j] = ret;
        }
    }

    int ans = m;
    int l = 1, r = m-1;
    while(l <= r){
        int md = (l+r)>>1;

        vector<pair<ll, ll>> dA(n*2);
        for(int i = 0; i < n*2; i++){
            ll val = 0;
            for(int j = 0; j < md;j++){
                val = (val * p2 + A[i][j]) % mod; 
            }           
            dA[i] = mp(val, i);
        }
        ll base = 1;
        for(int  j = 0; j < md; j++) base = base * p2 % mod;
        sort(all(dA));

        bool ok = 1;
        for(int f  =1 ; f < n*2; f++){
            if(dA[f].x == dA[f-1].x && (dA[f].y <n) != (dA[f-1].y < n)){
                ok = 0;
                break;
            }
        }

        if (ok) {
            ans = md;
            r = md - 1;
            continue;
        }

        for(int j = md; j < m; j++){
            for(auto& [a,b] : dA){
                a = (a * p2 + A[b][j]) % mod;
                a = (a + mod - A[b][j-md] * base % mod) % mod;
            }

            sort(all(dA));
            // cout << "Index: " << j << " => ";

            // for(auto[u,v ]: dA) cout << "(" << u << ' ' << v<< ") ";
            // cout << '\n';
            ok = 1;
            for(int f  = 1 ; f < n*2; f++){
                if(dA[f].x == dA[f-1].x && (dA[f].y <n) != (dA[f-1].y < n)){
                    ok = 0;
                    break;
                }
            }
            if (ok) break;
        }

        if (ok){
            ans = md;
            r = md - 1;
        }
        else l = md + 1;
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
