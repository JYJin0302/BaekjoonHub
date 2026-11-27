#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define x first
#define y second

vector<ll> A[101010];

void solve(){
    
    ll x, k;
    cin >> x >> k;

    for(int i =0 ; i < k; i++){
        int t;cin >> t;

        vector<ll> B(t);
        for(auto& f : B) cin >> f;
        
        ll val = 0;
        ll mn = 0;
        for(int j = 0; j < t; j++){
            val += B[j];
            mn = min(mn, val);
            if (val > 0){
                A[i].push_back(mn);
                A[i].push_back(val);

               // cout << "ADD: " << mn << ' ' << val << '\n';
                val = 0;
                mn = 0;
            }
        }
    }

    set<pair<ll, pair<int, int>>> st;
    for(int i =0 ; i < k; i++){
        if (!A[i].empty()){
            st.insert(mp(-A[i][0], mp(i, 0)));
        }
    }

    while(!st.empty()){
        auto f = *st.begin();
        st.erase(st.begin());
        if (f.x > x) break;
        //cout << x << " | " << f.x << ' '<< f.y.x << ' ' << f.y.y  << '\n';
        x += A[f.y.x][f.y.y + 1];

        int ix = f.y.y + 2;
        if (ix < int(A[f.y.x].size())){
            st.insert(mp(-A[f.y.x][ix], mp(f.y.x, ix)));
        }
    }

    cout << x << '\n';
    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}