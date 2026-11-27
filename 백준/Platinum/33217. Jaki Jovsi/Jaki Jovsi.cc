#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve(){

    ll l, n;
    cin >> l >> n;

    vector<pair<ll, ll>> L, R, tmp;

    ll minx = l, maxx = -1;
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;

        if (a <= b) L.push_back(mp(a, b)), minx = min(minx, a), maxx = max(maxx, b);
        else R.push_back(mp(b, a)), minx = min(minx, b), maxx = max(maxx, a);
    }

    sort(all(L));
    sort(all(R));

    for(auto[a,b] : L){
        if (tmp.empty() || tmp.back().y < a){
            tmp.push_back(mp(a, b));
        }
        else tmp.back().y = max(tmp.back().y, b);
    }
    L = tmp;
    tmp.clear();
    
    for(auto[a,b] : R){
        if (tmp.empty() || tmp.back().y < a){
            tmp.push_back(mp(a, b));
        }
        else tmp.back().y = max(tmp.back().y, b);
    }
    R = tmp;

    // cout << "REs: \n";
    // for(auto[a,b] : L) cout << a << ' '<< b << " | ";
    // cout << '\n';
    // for(auto[a,b] : R) cout << a << ' '<< b << " | ";
    // cout << '\n';

    ll ans = 2 * l;
    int Ls = L.size();
    int Rs = R.size();
    if (Ls && Rs){
        vector<ll> dpL(Rs), dpR(Rs);
        for(int i = 0; i < Rs; i++){
            dpL[i] = min((R[i].y-R[i].x) * 2 + (i ? dpL[i-1] : 0), R[i].y - minx);
        }
        for(int i = Rs-1; i >= 0; i--){
            dpR[i] = min((R[i].y - R[i].x) * 2 + (i == Rs-1 ? 0 : dpR[i+1]), maxx - R[i].x);
        }

        ll mn = dpR[0];
        for(int i = 0 ; i < Rs; i++){
            mn = min(mn, dpL[i] + (i == Rs-1 ? 0 : dpR[i+1]));
        }
        ans = min(ans, mn + maxx-minx);

        swap(L, R);
        swap(Ls, Rs);
        dpL = vector<ll>(Rs), dpR = vector<ll>(Rs);
        for(int i = 0; i < Rs; i++){
            dpL[i] = min((R[i].y-R[i].x) * 2 + (i ? dpL[i-1] : 0), R[i].y - minx);
        }
        for(int i = Rs-1; i >= 0; i--){
            dpR[i] = min((R[i].y - R[i].x) * 2 + (i == Rs-1 ? 0 : dpR[i+1]), maxx - R[i].x);
        }

        mn = dpR[0];
        for(int i = 0 ; i < Rs; i++){
            mn = min(mn, dpL[i] + (i == Rs-1 ? 0 : dpR[i+1]));
        }
        ans = min(ans, mn + maxx-minx);
    }
    else ans = maxx - minx;

    cout << ans << '\n';


}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
