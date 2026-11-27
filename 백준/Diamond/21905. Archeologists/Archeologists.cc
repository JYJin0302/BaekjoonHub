#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;

#define mp make_pair
#define x first
#define y second

void solve(){
    
    int n;
    cin >> n;
    vector<ll> A(n + 1);
    for(int i = 1; i <= n; i++) cin >> A[i];

    vector<ll> sA(n+1);
    for(int i =1; i <= n; i++){
        sA[i] = sA[i-1] + A[i];
    }

    
    set<pair<ll, ll>> st;
    st.insert(mp(0, 0));

    vector<int> match(n+1, -1);

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll v = sA[i];
        if ((*st.begin()).x < v){
            int ix = (*st.begin()).y;
            match[i] = ix;
            ans += v - (*st.begin()).x;
            
            if (match[ix] != -1){
                match[ix] = -1;
            }
            else st.erase(st.begin());
        }
        st.insert(mp(v, i));
    }
    cout << ans << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}