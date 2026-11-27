#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {
    
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    set<pair<int, int>> st;
    st.insert(mp(A[0], 0));

    ll ans = 0;
    cout << 0 << '\n';
    for(int i= 1;i < n; i++){
        auto iter = st.lower_bound(mp(A[i], -1));

        int res = 0;
        if (iter == st.begin()){
            res = (*iter).y + 1;
        }
        else if (iter == st.end()){
            --iter;
            res = (*iter).y + 1;
        }
        else{
            res = (*iter).y + 1;
            iter--;
            res = max(res, (*iter).y + 1);
        }

        ans += res;
        cout << ans << '\n';
        st.insert(mp(A[i], res));
    }


}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}