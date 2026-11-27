#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const ll INF = 5e18;
ll A[10001010];

void solve(){
    
    ll n, l, r, x, y, z, b1, b2;
    cin >> n >> l >> r>> x >> y>> z >> b1 >> b2;

    A[0] = b1;
    A[1] = b2;
    for(int i =2; i < n; i++){
        A[i] = A[i-2] * x + A[i-1] * y + z;
        A[i] &= 0xFFFFFFFF;
    }

    for(int i = 0; i < n; i++){
        A[i] = A[i] % (r - l + 1) + l;
    }

    // for(int i =0 ; i < n; i++) cout << A[i] << ' ';
    // cout << '\n';

    ll ans = INF;

    bool isZ = 0;
    array<ll, 4> B = {1, 1, -1, -1}; // neg LArg, neg small, pos Small, pos Large
    for(int i = n-1; i >= 0; i--){
        if (isZ && A[i] < 0) ans = min(ans, 0ll);
        if (B[0] < 0 && A[i] < B[0]) ans = min(ans, A[i] * B[0]);
        if (B[1] < 0 && A[i] < B[1]) ans = min(ans, A[i] * B[1]);
        if (B[2] > 0 && A[i] < B[2]) ans = min(ans, A[i] * B[2]);
        if (B[3] > 0 && A[i] < B[3]) ans = min(ans, A[i] * B[3]);

        if (A[i] == 0) isZ = 1;
        else if (A[i] < 0){
            if (B[0] > 0) B[0] = A[i];
            else B[0] = min(B[0], A[i]);
            if (B[1] > 0) B[1] = A[i];
            else B[1] = max(B[1], A[i]);
        }
        else{
            if (B[2] < 0) B[2] = A[i];
            else B[2] = min(B[2], A[i]);
            if (B[3] < 0) B[3] = A[i];
            else B[3] = max(B[3], A[i]);
        }
    }

    vector<ll> stk;
    // pos
    for(int i = 0; i < n; i++){
        if( A[i] <= 0) continue;
        while(!stk.empty() && stk.back() >= A[i]) stk.pop_back();
        if(!stk.empty()) ans = min(ans, A[i] * stk.back());
        stk.push_back(A[i]);
    }
    stk.clear();
    for(int i = n-1; i >=0 ; i--){
        if( A[i] >= 0) continue;
        int val = -A[i];
        while(!stk.empty() && stk.back() >= val) stk.pop_back();
        if(!stk.empty()) ans = min(ans, val * stk.back());
        stk.push_back(val);

        // for(auto f: stk) cout << f<< ' ';
        // cout << '\n';
    }
    stk.clear();

    
    if (ans == INF) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
