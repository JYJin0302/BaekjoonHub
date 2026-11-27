#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair


void solve(){

    ll n, L;
    cin >> n >> L;

    vector<pair<ll, ll>> A; // (a, b) : a 초까지 잡을 수 있음, b원

    for(int i =0 ; i < n; i++){
        ll x, y, c;
        cin >> x >> y >> c;

        // turn
        ll val = x *x + y * y;
        if (val > L*L) continue;

        ll T = 0;
        ll tmp = sqrtl(val);
        while(tmp * tmp > val) tmp--;
        while((tmp+1)*(tmp+1) <= val) tmp++;

        if(tmp * tmp == val){
            T = L - tmp;
        }
        else {
            T = L - tmp - 1;
        }

        A.push_back(mp(T, c));
    }
    sort(all(A));

    if (A.empty()){
        cout << 0 << '\n';
        return;
    }

    ll ans = 0;
    int ix = (int)A.size() - 1;
    ll curT = A[ix].x;

    priority_queue<ll> pq;
    while(curT >= 0){
        while(ix >= 0 && A[ix].x == curT){
            pq.push(A[ix].y);
            ix--;
        }

        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
            curT--;
        }
        else{
            if(ix >= 0) curT = A[ix].x;
            else break;
        }
    }

    cout << ans << '\n';

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}