#include <bits/stdc++.h>
using namespace std;
using ll = long long;

typedef pair<ll, ll> P;

#define x first
#define y second

ll dist(P& a, P& b){
    ll d = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    ll v = sqrt(d/100);
    
    return v + (d - 100*v*v > 0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<P> A(n+2);
    A[0] = {0, 0};
    for(int i = 1; i <= n; i++) cin >> A[i].x >> A[i].y;
    A[n+1] = {10000, 10000};
    
    bool dp[1003];
    
    int l = 1, r = 15000;
    int ans = 15000;
    while(l <= r){
        
        int mid = (l+r)/2;
        memset(dp, 0, sizeof(dp));
        
        queue<P> q;
        q.push({0, 0});
        
        bool ok = 0;
        while(!q.empty() && !ok){
            
            int a, b;
            tie(a, b) = q.front();
            q.pop();
            
            if (dist(A[a], A[n+1]) <= mid){
                ok = 1;
                break;
            }
            
            if (b < k){
                for (int i = 1; i <= n; i++){
                    if (!dp[i] && dist(A[i], A[a]) <= mid) {
                        dp[i] = 1;
                        q.push({i, b+1});
                    }
                }
            }
        }
        
        while(!q.empty()) q.pop();
        
        if (ok){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    
    cout << ans;
}