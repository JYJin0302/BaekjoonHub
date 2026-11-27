#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

ll gcd(ll a, ll b){
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b%a, a);
}

void solve(){
    
    
    int n;
    cin >> n;

    vector<pair<ll, ll>> A(n);
    for(int i =0 ; i< n; i++){
        cin >> A[i].x >> A[i].y;
        A[i].x *= A[i].x;
        A[i].y *= A[i].y;
    }

    int ans = 0;
    for(int i =0 ; i< n; i++){
        map<pair<ll, ll>, int> cnt;
        ll x1 = A[i].x;
        ll y1 = A[i].y;
        int bs = 0;
        int mx = 0;
        for(int j = 0; j < n; j++){
            
            ll x2 = A[j].x;
            ll y2 = A[j].y;

            x2 -= x1;
            y2 -= y1;
            if (x2 < 0) x2*=-1, y2 *= -1;
            if (x2 == 0 && y2 < 0) y2 *= -1;

            ll g = gcd(abs(x2), abs(y2));
            if (g) x2/=g, y2/=g;

            if (x2 == 0 && y2 == 0){
                bs++;
            }
            else if (x2 >= 0 && y2 >= 0) {}
            else {
                cnt[mp(x2, y2)]++;
                mx = max(mx, cnt[mp(x2, y2)]);
            }
        }

        //cout << " i: " << i << " => " << bs << ' ' << mx << '\n';

        ans = max(ans, bs + mx) ;
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