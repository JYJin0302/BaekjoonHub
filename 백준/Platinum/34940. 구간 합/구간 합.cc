#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

ll fastPow(ll b, ll ex){
    ll res = 1;
    while(ex){
        if (ex & 1) res = res * b % mod;
        b =b * b % mod;
        ex  >>=  1;
    }
    return res;
}

bool cmp(array<int, 3> a1, array<int, 3> a2){
    return a1[1] - a1[0] < a2[1] - a2[0];
}


void solve(){
    
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> A;

    for(int i = 0; i < n; i++){
        int l, r, v;
        cin >> l >> r >> v;

        A.push_back({l, r, v});
    }
    sort(all(A), cmp);

    ll ans = 1;
    int ix = 0;

    vector<ll> dif(m+10);
    ll curSum = 0;
    ll curDif = 0;

    for(int D = 1; D <= m; D++){
        //cout << "pre1: " << curDif << ' '<< curSum << " | " << dif[D] <<  '\n';
        curDif += dif[D];
        curDif = (curDif % (mod-1) + mod - 1) % (mod-1);
        curSum = (curSum + curDif) % (mod-1);

       // cout << "pre2: " << curDif << ' '<< curSum << '\n';
        while(ix < n && A[ix][1] - A[ix][0] <= D){
           // cout << "process: " << A[ix][0] << ' ' << A[ix][1] << ' ' << A[ix][2] << '\n';
            int d = A[ix][1] - A[ix][0];

            int m1 = max(1, A[ix][1] - D + 1);
            int m2 = min(m-D+1, A[ix][0]);
            int len = m2 - m1 + 1;

            curSum += 1ll * len * A[ix][2];
            curSum %= (mod-1);

            curDif += A[ix][2];
            curDif %= mod-1;

            if (D + m1 <= m + 5) dif[D+m1] -= A[ix][2];
            m2 += D-1;
            m2 = m - m2 + 1;
            if (D + m2 <= m + 5) dif[D+m2] -= A[ix][2];            

           // cout << "add: " << m1 << ' '<< m2 << '\n';

            ix++;
        }

        //cout << "ans add: " << D << ' ' << curSum << " | " << curDif << '\n';
        ans = ans * fastPow(D, curSum) % mod;
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