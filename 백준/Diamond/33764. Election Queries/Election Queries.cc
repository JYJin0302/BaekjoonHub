#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair


int cnt[202020];
set<int> st;
set<int> lst[202020];

void addNum(int x){
    int cc = cnt[x];
    cnt[x]++;
    
    if (cc){
        lst[cc].erase(x);
        if (lst[cc].empty()) st.erase(cc);
    }

    cc = cnt[x];
    lst[cc].insert(x);
    st.insert(cc);
}
void delNum(int x){
    int cc = cnt[x];
    cnt[x]--;

    lst[cc].erase(x);
    if (lst[cc].empty()) st.erase(cc);

    if(cnt[x]){
        cc = cnt[x];
        lst[cc].insert(x);
        st.insert(cc);
    }
}


void solve(){
    
    int n, q;
    cin >> n >> q;

    vector<int> A(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }
    
    for(int i = 1; i <= n; i++) if (cnt[i]) {
        st.insert(cnt[i]);
        lst[cnt[i]].insert(i);
    }

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;

        delNum(A[a]);
        A[a] = b;
        addNum(A[a]);

        vector<int> res;
        for(auto f : st) res.push_back(f);

        int mxCnt = res.back();

        int ans = 0;
        int ix = (int)res.size() - 1;
        int mn = *lst[mxCnt].begin();
        int mx = *lst[mxCnt].rbegin();

        for(auto f : st){
            while(ix && res[ix-1] + f >= mxCnt){
                ix--;
                mn = min(mn, *lst[res[ix]].begin());
                mx = max(mx, *lst[res[ix]].rbegin());
            }
            int l = *lst[f].begin();
            int r = *lst[f].rbegin();
            ans = max({ans, r - mn, mx - l});
        }

        cout << ans << '\n';
    }

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
