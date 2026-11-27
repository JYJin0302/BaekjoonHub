#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n, q;
const int mod = 998244353;

int fw[505050];
int cnt[505050];
void update(int ix, int val){
    while(ix <= n + 10){
        fw[ix] += val;
        ix += ix & -ix;
    }
}
int getS(int ix){
    int res = 0;
    while(ix){
        res += fw[ix];
        ix -= ix & -ix;
    }
    return res;
}

ll val[505050];

void solve(){
    
    cin >> n >> q;

    vector<ll> A(n+1);
    for(int i =1; i <= n; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }

    vector<ll> B = A;
    ll ans = 0;
    sort(all(B));
    for(int i = n - 1; i >= 1; i--){
        ll mul = n-i;
        ll v = B[i] ;
        v = v * (v-1)/2 % mod;
        v = v * mul % mod;

        ans += v;
        val[i] = v;
    }

    for(int i = 0; i <= n;i++){
        update(i+1, cnt[i]);
    }

    while(q--){

        int ix, dif;
        cin >> ix >> dif;
        if (dif == 1){
            int cur = A[ix];
            int tx = getS(cur + 1);

            ans = (ans + mod - val[tx]) % mod;
            
            A[ix]++;

            ll mul = n - tx;
            ll v = A[ix] * (A[ix] - 1) / 2 % mod;
            v = v * mul % mod;

            val[tx] = v;
            ans = (ans + v) % mod; 

            update(cur+1, -1);
            update(cur+2, 1);
        }
        else{

            int cur = A[ix];
            int tx = getS(cur) + 1;

            ans = (ans + mod - val[tx]) % mod;
            
            A[ix]--;
            ll mul = n - tx;
            ll v = A[ix] * (A[ix] - 1) / 2 % mod;
            v = v * mul % mod;

            val[tx] = v;
            ans = (ans + v) % mod; 

            update(cur+1, -1);
            update(cur, 1);
        }

        cout << ans << '\n';
    }
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