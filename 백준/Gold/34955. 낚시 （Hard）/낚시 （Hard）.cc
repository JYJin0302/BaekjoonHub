#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){

    int n, m;
    cin >> n >> m;
    vector<ll> A(n), B(m);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;

    sort(all(A));
    sort(all(B));

    vector<pair<int, int>> ans;
    ll ret = 0;
    int ix = m-1;
    for(int i = n-1; i >=0 && ix >= 0; i--){
        if (A[i] < B[ix]) {
            ret += B[ix];
            ans.push_back(mp(i, ix));
            ix--;
        }
    }
    
    reverse(all(ans));

    multiset<int> st;
    for(auto f: B) st.insert(f);

    vector<string> rep;
    ix = 0;
    for(auto[a,b]: ans){
        rep.push_back("fish " + to_string(A[a]));
        
        int cur = A[a];
        auto iter = st.lower_bound(cur + 1);

        while(*iter != B[b]){
            cur = *iter;
            st.erase(iter);
            rep.push_back("bait " + to_string(cur));
            rep.push_back("fish " + to_string(cur));
            iter = st.lower_bound(cur + 1);
        }
        st.erase(iter);
    }

    cout << (int)rep.size() << '\n';
    for(auto f : rep) cout << f<< '\n';
    cout << ret << '\n';

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
