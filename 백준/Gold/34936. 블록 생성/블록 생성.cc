#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    int n, t, k;
    cin >> n >> t >> k;

    vector<array<int, 3>> Q;
    for(int i =0 ; i < n; i++){
        int ty;
        cin >> ty;
        if (ty == 1){
            int a, b;
            cin >> a>> b;
            Q.push_back({ty, a, b});
        }
        else{
            int a;
            cin >> a;
            Q.push_back({ty, a, -1});
        }
    }

    multiset<pair<int, int>> st;

    ll ans = 0;
    for(int i = 0; i < n; i++){
        int a = Q[i][0];
        int b = Q[i][1];
        int c = Q[i][2];

        //cout << a << ' '<< b<< ' ' << c << '\n';

        if (a == 1){
            st.insert(mp(-c, b));
        }
        else{
            int cnt = 0;
            while(cnt < k && !st.empty()){
                auto f = *st.begin();
                st.erase(st.begin());
               // cout << "Check: " << f.first << ' ' << f.second << '\n';
                if (f.second < b - t) continue;
                cnt++;
                ans -= f.first;
            }
        }
    }
    cout << ans << '\n';




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