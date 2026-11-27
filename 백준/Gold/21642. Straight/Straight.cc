#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    int n, s, m;
    cin >> n >> m >> s;

    vector<int> A(m);
    for(auto& i : A) cin >> i;
    sort(all(A));
    A.erase(unique(all(A)), A.end());

    int ans = 0;

    int nd = m - s;

    vector<pair<int, int>> res;
    for(int i = nd-1; i < (int)A.size(); i++){
        int l = A[i - nd + 1];
        int r = A[i];
        //cout << l << ' '<< r << '\n';

        if (r - m + 1 <= l) {
            int tl = max(1, r -m + 1);
            int tr = min(l, n - m  + 1);
            if (tl <= tr) res.push_back(mp(tl, tr));
        }
    }

    if(res.empty()){}
    else{
        sort(all(res));
        auto[a,b] = res[0];
        for(int i = 1; i < (int)res.size(); i++){
            auto[c,d] = res[i];
            if (c > b){
                ans += b - a + 1;
                a = c;
                b = d;
            }
            else b = max(b, d);
        }
        ans += b - a + 1;
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
