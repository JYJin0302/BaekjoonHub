#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


vector<ll> rec[5050];

void solve(){
    
    ll W, H;
    cin >> W >> H;

    int n;
    cin >> n;

    vector<array<ll, 4>> R;

    vector<ll> h, w;
    h.push_back(0);
    for(int i =0 ; i < n; i++){
        ll x1, x2, y1 , y2;
        cin >> x1 >> y1>> x2 >> y2;
        R.push_back({x1, y1, x2, y2});
        h.push_back(y2);
        w.push_back(x1);
        w.push_back(x2);
    }
    sort(all(h));
    h.erase(unique(all(h)), h.end());

    w.push_back(0);
    w.push_back(W);
    sort(all(w));
    w.erase(unique(all(w)), w.end());

    for(auto& f : R){
        f[0] = lower_bound(all(w), f[0]) - w.begin();
        f[2] = lower_bound(all(w), f[2]) - w.begin();
    }

    int sn =(int)w.size();


    ll ans = 0;
    for(auto curH : h){

        vector<ll> lst(sn, H);

        for(int j = 0; j < sn; j++) rec[j].clear();

        for(int i =0 ; i< n ;i++){
            if (R[i][3] <= curH) continue;
            if (R[i][1] <= curH){
                rec[R[i][0]].push_back(curH);
                rec[R[i][2]].push_back(-curH - 1);
            }
            else{
                rec[R[i][0]].push_back(R[i][1]);
                rec[R[i][2]].push_back(-R[i][1] - 1);
            }
        }

        multiset<ll> st;
        st.insert(H);
        for(int j = 0; j < sn; j++){
            for(auto f: rec[j]){
                if (f >= 0) st.insert(f);
                else st.erase(st.find(-f - 1));
            }

            lst[j] = *st.begin() - curH;
        }

        stack<pair<ll, ll>> stk;
        lst[sn-1] = 0;
        stk.push(mp(lst[0], 0));
        for(int i = 1; i < sn; i++){
            int ti = i;
            while(!stk.empty() && stk.top().x >= lst[i]){
                ll X = w[i] - w[stk.top().y];
                ll Y = stk.top().x;
                ans = max(ans, X * Y);
                ti = stk.top().y;
                stk.pop();
            }
            stk.push(mp(lst[i], ti));
        }
    }

    cout << ans << '\n';



}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}