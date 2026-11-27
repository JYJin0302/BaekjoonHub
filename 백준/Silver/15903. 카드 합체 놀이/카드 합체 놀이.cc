#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

void solve(){
    
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for(auto& i : A) cin >> i;

    multiset<ll> st;
    for(auto f : A) st.insert(f);

    while(m--){
        auto f = (*st.begin());
        st.erase(st.begin());
        auto f2 = (*st.begin());
        st.erase(st.begin());
        st.insert(f+ f2);
        st.insert(f+ f2);
    }

    ll res = 0;
    for(auto f : st) res += f;

    cout << res << '\n';
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
