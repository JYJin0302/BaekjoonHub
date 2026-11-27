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

    vector<ll> A(n), B(n);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;
    B.push_back(0);

    int L = 0, R = n - 1, ans = -1;
    while(L <= R){
        int md = (L+R)>>1;

        bool ok = 1;
        int ix = 0, rem = B[0];
        for(int i = 0; i < n; i++){
            if (ix < i - md) {
                ix = i - md;
                rem = B[ix];
            }

            while(ix < n && rem == 0) {
                ix++;
                rem = B[ix];
            }
            if (ix == n) {
                ok = 0;
                break;
            }

            int cur = A[i];
            while(ix < n && cur){
                if (rem == 0) {
                    ix++;
                    rem = B[ix];
                }
                if(ix == n || ix > i + md) {
                    ok = 0;
                    break;
                }
                int val = min(cur, rem);
                cur -= val;
                rem -= val;
            }

            if (!ok) break;

        }

        if (ok){
            ans = md;
            R = md- 1;
        }
        else L= md + 1;
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

