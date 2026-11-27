#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<pair<ll ,ll>> adj[101010];

ll distS[101010];
ll distE[101010];


void solve(){
    
    int n, m;
    cin >> n >> m;

    while(m--){
        int a, b, c;
        cin >> a>> b >> c;

        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    memset(distS, -1, sizeof distS);
    memset(distE, -1, sizeof distE);
    set<pair<ll, ll>> st;
    st.insert(mp(0, 1));
    while(!st.empty()){
        auto f= *st.begin(); st.erase(st.begin());
        if (distS[f.y] != -1) continue;
        distS[f.y] = f.x;
        for(auto d : adj[f.y]){
            if (distS[d.x] == -1){
                st.insert(mp(f.x + d.y, d.x));
            }
        }
    }

    st.insert(mp(0, n));
    while(!st.empty()){
        auto f = *st.begin(); st.erase(st.begin());
        if (distE[f.y] != -1) continue;
        distE[f.y] = f.x;
        for(auto d : adj[f.y]){
            if (distE[d.x] == -1){
                st.insert(mp(f.x + d.y, d.x));
            }
        }
    }

    // for(int i= 1; i <= n; i++) cout << distS[i] << ' ' << distE[i] << " | ";
    // cout << '\n';

    vector<array<ll, 3>> A, B;
    for(int i = 1; i <= n; i++){
        A.push_back({distS[i], distE[i], i});
    }
    sort(all(A));

    for(int i = 0; i < n;i++){
        if(i == n-1 || A[i+1][0] != A[i][0]) {
            while(!B.empty() && B.back()[1] <= A[i][1]) B.pop_back();
            B.push_back(A[i]);
        }
    }

    int q;
    cin >> q;
    while(q--){
        ll a, b;
        cin >> a>> b;

        ll ans = 0;
        int ansi = 1;
        int tl = 0;
        int tr = (int)B.size() - 1;
        while(tl <= tr){
            int md = (tl+tr)>>1;

            ll v1 = B[md][0] * a;
            ll v2 = B[md][1] * b;
            ll val = min(v1, v2);
            ans = max(ans, val);
            if (ans == val) ansi= B[md][2];

            if (v1 > v2){
                tr = md - 1;
            }
            else tl = md + 1;
        }

        cout << ansi << '\n';

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
