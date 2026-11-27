#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
typedef long long ll;

#define mp make_pair

void solve(){
    
    int n;
    cin >> n;
    vector<ll> A(n);
    for(auto& i : A) cin >> i;

    vector<ll> B(n);
    ll tot = 0;
    for(int i =0; i < n;i++){
        B[i] = A[(i+1)%n] - A[i];
        if (B[i] >= 0) tot += B[i];
    }


    int off = min_element(all(A)) - A.begin();
    ll base = A[off];
    
    // cout << off << ' ' << base << '\n';
    // for(int i =0 ;i < n;i++){
    //     cout << B[(i+off)%n]<< ' ';
    // }
    // cout << '\n';

    vector<pair<ll, ll>> stk; // pos

    vector<pair<int, int>> ans;
    for(int i = n-1; i >= 0 && base; i--){
        int ix=(i+off)%n;
        ll val = B[ix];
        if (val == 0) continue;
        if (val > 0){
            stk.push_back(mp(ix, val));
        }
        else{   
            val = abs(val);
            while(!stk.empty()){
                auto[a,b] =stk.back();
                ll tst = min(base, b);
                tst = min(tst, val);

                base -= tst;
                val -= tst;
                b -= tst;
                stk.back().second -= tst;
                B[a] -= tst;
                B[ix] += tst;

                for(int j =0;j < tst;j++){
                   // cout << "ADd: "<< a<< ' ' << ix << '\n';
                    ans.push_back(mp(a, ix));
                }
                if(b == 0) stk.pop_back();
                if(base == 0 || val == 0) break;
            }
        }
    }

    ll ret = tot + base;
    if(ret > 200000){
        cout << ret << '\n';
        return;
    }

    stk.clear();
    for(int i =0; i < n; i++){
        int ix = (i + off)% n;
        if(B[ix] > 0){
            stk.push_back(mp(ix, B[ix]));
        }
        else if(B[ix] < 0){
            ll cnt = -B[ix];
            while(!stk.empty()){
                auto[a,b] =stk.back();
                ll rr= min(b, cnt);
                b -= rr;
                stk.back().second -= rr;
                cnt -= rr;

                for(int j =0; j < rr; j++){
                    ans.push_back(mp(a, ix));
                }
                if(b == 0) stk.pop_back();
                if(cnt == 0) break;
            }

            if(cnt){
                assert(0);
            }
        }
    }


    cout << ret << '\n';
    for(auto[a,b]: ans) cout << (a + 1) % n + 1 << ' ' << b + 1 << '\n';
    for(int i =0; i< base; i++) cout << 1 << ' ' << n << '\n';

}

int main(){ 
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}