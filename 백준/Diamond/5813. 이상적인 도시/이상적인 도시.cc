#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int d8x[] = {-1, 1, 1, -1};
int d8y[] = {-1, -1, 1, 1};

struct P{
    ll d, num;
};

map<pair<int, int>, int> ix;
vector<pair<ll, ll>> inp;

int ord[100001];

P dp[100001];

void bfs(){
    
    ord[1] = 1;
    queue<int> q;
    q.push(1);
    
    while(!q.empty()){
        
        int a = q.front();
        int x, y;
        tie(x, y) = inp[a];
        
        q.pop();
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            int na = ix[{nx, ny}];
            if (na != 0 && ord[na] == 0){
                ord[na] = ord[a] + 1;
                q.push(na);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    
    inp= vector<pair<ll, ll>> (n+1);
    for (int i = 1; i <= n; i++){
        ll x, y;
        cin >> x >> y;
        
        inp[i] = {x, y};
    }
    inp[0] = {-mod*mod, -mod*mod};
    sort(inp.begin(), inp.end());
    
    for (int i =1 ; i <= n; i++){
        ll x, y;
        tie(x, y) = inp[i];
        ix[{x, y}] = i;
    }
    // 방문 순서 저장
    bfs();
    
    vector<pair<int, int>> q;
    for (int i = 1; i <= n; i++){
        q.push_back({ord[i], i});
    }
    sort(q.rbegin(), q.rend());
    
    int mt = q[0].first;
    
    ll ans = 0;
    for (auto i : q){
        
        int a, b;
        tie(a, b) = i;
        
        ll dpx = 0, dpy = 1;
        if (a != mt) {
            
            int x, y;
            tie(x, y) = inp[b];
            
            for (int j = 0; j < 4; j++){
                int p1 = ix[{x + dx[j], y + dy[j]}];
                int p2 = ix[{x + dx[(j+1)%4], y + dy[(j+1)%4]}];
                int p3 = ix[{x + d8x[j], y + d8y[j]}];
                
                if (p1 != 0 && ord[p1] == a+1){
                    dpx += dp[p1].d + dp[p1].num;
                    dpx %= mod;
                    dpy += dp[p1].num;
                }
                
                if (p1 != 0 && p2 != 0 && ord[p1] == ord[p2] && ord[p1] == a + 1){
                    ans += (dp[p1].d + dp[p1].num)*dp[p2].num + (dp[p2].d + dp[p2].num)*dp[p1].num;
                    ans %= mod;
                    if (p3 != 0 && ord[p3] == a + 2){
                        dpx -= dp[p3].d + dp[p3].num*2;
                        dpx = (dpx + mod *100000) % mod;
                        dpy -= dp[p3].num;
                        
                        ans -= (dp[p3].d + dp[p3].num*2)*(dp[p2].num + dp[p1].num - dp[p3].num*2) + (dp[p1].d + dp[p1].num+ dp[p2].d + dp[p2].num)*dp[p3].num;
                        ans = (ans + mod*100000) % mod;
                    }
                }
            }
            
            for (int j = 0; j < 4; j ++){
                int p1 = ix[{x + dx[j], y + dy[j]}];
                int p2 = ix[{x + dx[(j+2)%4], y + dy[(j+2)%4]}];
                
                int p3 = ix[{x + dx[(j+1)%4], y + dy[(j+1)%4]}];
                int diag1 = ix[{x + d8x[j], y + d8y[j]}];
                int diag2 = ix[{x + d8x[(j+1)%4], y + d8y[(j+1)%4]}];
                
                
                if (p1 != 0 && p2 != 0 && ord[p1] == ord[p2] && ord[p1] == a + 1){
                    if (j < 2){
                    ans += (dp[p1].d + dp[p1].num)*dp[p2].num + (dp[p2].d + dp[p2].num)*dp[p1].num;
                    ans %= mod;
                    }
                    
                    if (p3 != 0 && ord[p3] == a + 1){
                        if (diag1 != 0 && ord[diag1] == a+2) {
                            ans -= (dp[diag1].d + dp[diag1].num*2)*dp[p2].num + (dp[p2].d + dp[p2].num)*dp[diag1].num;
                            ans = (ans + mod*100000) % mod;
                        }
                        if (diag2 != 0 && ord[diag2] == a+2) {
                            ans -= (dp[diag2].d + dp[diag2].num*2)*dp[p1].num + (dp[p1].d + dp[p1].num)*dp[diag2].num;
                            ans = (ans + mod*100000) % mod;
                        }
                        if (diag1 != 0 && ord[diag1] == a+2 && diag2 != 0 && ord[diag2] == a+2) {
                            ans += (dp[diag1].d + dp[diag1].num*2)*dp[diag2].num + (dp[diag2].d + 2*dp[diag2].num)*dp[diag1].num;
                            ans %= mod;
                        }
                        
                    }
                    
                }
            }
        }
        dp[b].d = dpx;
        dp[b].num = dpy;
        ans = (ans + dpx) % mod;
    }
    cout << ans;
}
