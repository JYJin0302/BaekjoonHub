#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define all(x) x.begin(), x.end()

int getI(vector<int>& v){
    int res = 0;
    for(auto f : v){
        res = res * 10 + f - 1;
    }
    return res;
}

void solve() { 
    
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto& i : A) cin >> i;

    int m;
    cin >> m;

    vector<array<int, 3>> oper;
    while(m--){
        int a, b, c;
        cin >> a>> b >> c;
        a--, b--;
        oper.push_back(array<int, 3>{a, b, c});
    }

    map<int, int> dp;
    set<pair<int, int>> st;
    st.insert(mp(0, getI(A)));
    while(!st.empty()){

        auto[a,b] = *st.begin(); st.erase(st.begin());
        if (dp[b] != 0) continue;
        dp[b] = a + 1;

        vector<int> tb;
        for(int i =0 ; i < n; i++){
            tb.push_back(b % 10 + 1); b /= 10;
        }
        reverse(all(tb));

        bool ok = 1;
        for(int i = 1; i < n; i++){
            if (tb[i] < tb[i-1]) ok = 0;
        }

        if (ok){
            cout << a << '\n';
            return;
        }

        for(auto f : oper){
            swap(tb[f[0]], tb[f[1]]);

            int vv = getI(tb);
            if (dp[vv] == 0){
                st.insert(mp(a + f[2], vv));
            }
            swap(tb[f[0]], tb[f[1]]);
        }

    }   
    cout << -1 << '\n';


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
