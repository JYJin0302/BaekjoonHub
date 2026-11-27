#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> inp[100];

bool chk[101][101];

ll dp[33][33][33];

void solve(){

    const ll INF = 1e18;

    ll r, s, m ,d, n;
    cin >> r >> s >> m >>d >>n;

    vector<ll> A(r+1);
    for(int i = 1; i <= r; i++) cin >>A[i];

    for(int i = 0; i <s + m + d; i++){

        ll k;
        cin >>k;

        vector<ll> tmp(k);
        for(auto &f : tmp)cin >>f;

        inp[i+1] = tmp;

    }

    while(n--){
        int a, b;
        cin >> a>>b;

        chk[a][b] = 1;
        chk[b][a] = 1;

    }

    ll ans = 0;
    for(int i = 1; i <= s; i++){
        for(int j =1 ; j <= m; j++){
            for(int k = 1; k <= d; k++){

                int ix = i;
                int jx = s+j;
                int kx = s+m+k;

                if (chk[ix][jx] || chk[jx][ix]) continue;
                if (chk[ix][kx] || chk[kx][ix]) continue;
                if (chk[jx][kx] || chk[kx][jx]) continue;

                set<int> st;
                for(auto f : inp[ix]){
                    st.insert(f);
                }
                for(auto f : inp[jx]){
                    st.insert(f);
                }
                for(auto f : inp[kx]){
                    st.insert(f);
                }

                ll res = 1;
                for(auto f : st){

                    if (INF / A[f] < res) {
                        cout << "too many";
                        return;
                    }

                    res *= A[f];
                }

                ans += res;

                if (ans > INF) {
                    cout <<"too many";
                    return;
                }

            }
        }
    }

    cout <<ans;




}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
