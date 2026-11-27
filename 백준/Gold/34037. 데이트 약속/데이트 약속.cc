#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const ll INF = 1e15;

void solve(){
    
    ll n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> A(m);
    for(auto& i : A) cin >> i.x >> i.y;
    A.push_back(mp(n+1, 0));
    m++;
    sort(all(A));

    vector<ll> dp(m+10, -INF);
    for(int i = 0; i < m; i++){

        ll minSum = 0;
        for(int j = i - 1; j >= 0; j--){    
            ll dist = A[i].x - A[j].x - 1;
            dp[i] = max(dp[i], dp[j] + dist * (dist+1) / 2 - minSum);
            minSum += A[j].y;
        }
        ll dist = A[i].x - 1;
        dp[i] = max(dp[i], dist * (dist+1)/2 - minSum);
    }
    cout << dp[m-1] << '\n';
    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}