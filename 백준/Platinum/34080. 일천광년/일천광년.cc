#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair


ll gcd(ll a, ll b){
    if (a == 0) return b;
    return gcd(b%a, a);
}

void solve(){

    ll n, x, y;
    cin >> n >> x >> y;

    if (n <= 10){
        vector<ll> tmp(n+1);
        tmp[0] = x, tmp[n] = y;

        while(1){
            int l = 0, r = n;
            while(tmp[l] == 0) l++;
            while(tmp[r] == 0) r--;

            if (r -l <=1 ){
                cout << r-l + 1 << '\n';
                for(int i = l; i <= r; i++) cout << i << ' ' << tmp[i] << '\n';
                return;
            }

            ll mn = min(tmp[l], tmp[r]);
            tmp[l+1] += mn, tmp[l] -= mn;
            tmp[r-1] += mn, tmp[r] -= mn;
        }
    }

    
    bool swp = 0;
    if(x > y) swap( x,y), swp = 1;
    ll g = gcd(x, y);

    ll cycle = y / g + x / g - 1;
   // cout << "Cycle: " << cycle << '\n';
    // cycle 지나면 cycle + 1만큼 길이가 줄어든다

    ll len = n + 1, offset = 0;
    ll mn1 = (len - 2) / (cycle + 1);
    len -= mn1 * (cycle + 1);
    offset += (y / g) * mn1;

    // 이제 cycle이 완성되지 않음
    
    // mini cycle - x 가 y를  넘을 때마다 길이 추가로 -1
    ll tL = 0, tR = len - 3, res = 0; // x가 res만큼 오른쪽 이동
    while(tL <= tR){
        ll md= (tL + tR) / 2;

        ll cnt = x * md / y;
        ll totLen = md + cnt;
        if (totLen <= len - 3){
            res = md;
            tL = md + 1;
        }
        else tR = md - 1;
    }

    offset += res;
    ll tcnt = x * res / y;
    len -= res + tcnt;

    vector<ll> tmp(len);
    tmp[0] = x;
    tmp[len-1] = y - x * res % y;
    tmp[len-2] += y - tmp[len-1];

    // cout << "Swapped: " << swp << " || " << offset << ' ' << "len: " << len  << '\n';
    // for(auto f: tmp) cout <<f << ' ';
    // cout << '\n';

    while(1){
        int l = 0, r=  len - 1;
        while(tmp[l] == 0) l++;
        while(tmp[r] == 0) r--;

        if (r-l <= 1){
            cout << r-l + 1 << '\n';
            if (!swp) {
                for(int i = l; i <= r; i++) cout << offset + i << ' ' << tmp[i] << '\n';
            }
            else {
                for(int i = r; i >= l; i--) cout << n - (offset + i) << ' ' << tmp[i] << '\n';
            }
            break;
        }

        ll mn = min(tmp[l], tmp[r]);
        tmp[l+1] += mn, tmp[l] -= mn;
        tmp[r-1] += mn, tmp[r] -= mn;
    }
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}