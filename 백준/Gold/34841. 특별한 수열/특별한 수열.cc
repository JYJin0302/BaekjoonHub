#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(auto& i :A ) cin >> i;

    if (n <= 2){
        for(int i =0 ; i < n; i++) cout << 1 << '\n';
        return;
    }

    set<int> st;
    set<int> Rs;
    st.insert(A[0]);
    st.insert(A[1]);
    Rs.insert(-A[0]);
    Rs.insert(-A[1]);

    map<int,int> cnt;
    int D = abs(A[0] - A[1]);
    cnt[D] = 1;

    vector<int> ans(n, 1);

    int mn = min(A[0], A[1]);
    int mx = max(A[0], A[1]);
    bool ok = 1;
    for(int i = 2; i < n; i++){
        int v = A[i];

        if (v <= mn){
            cnt[mn - v]++;
            ok = (cnt[mn-v] == i);
        }
        else if (v >= mx){
            cnt[v - mx]++;
            ok = (cnt[v-mx] == i);
        }
        else{
            int nx = *st.lower_bound(v);
            int pre = -*Rs.lower_bound(-v);

            cnt[nx-pre]--;
            cnt[nx-v]++;
            cnt[v-pre]++;
            ok = (cnt[v-pre] == i);
        }

        ans[i] = ok;

        st.insert(v);
        Rs.insert(-v);
        mn = min(mn, v);
        mx = max(mx, v);
    }

    for(auto f :ans) cout <<f << '\n';

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