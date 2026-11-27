#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool worm[202020];
vector<int> adj[202020];

int dist[202020];
int dist2[202020];

ll gcd(ll a, ll b){
    if(a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b% a, a);
}

void solve(){

    int n, m, k;
    cin >> n >> m >> k;

    for(int i =0 ;i  < k;i++){
        int x;
        cin >> x;
        worm[x] = 1;
    }

    for(int i =0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(dist, -1 ,sizeof dist);

    dist[n] = 0;
    queue<int> q;
    q.push(n);

    ll tot = 0;

    while(!q.empty()){
        
        int a = q.front();
        q.pop();

        if (worm[a]) tot += dist[a];

        for(auto f :adj[a]){
            if(dist[f] == -1){
                dist[f] = dist[a] + 1;
                q.push(f);
            }
        }
    }

    q.push(1);
    memset(dist2, -1, sizeof dist2);
    dist2[1] = 0;

    ll ansN = dist[1];
    ll ansD = 1;
    while(!q.empty()){

        int a=q.front();
        q.pop();

        if(worm[a]){
            ll tansN = tot - dist[a];
            ll tansD = k - 1;

            tansN += 1ll * (k-1) * dist2[a];

            ll g= gcd(tansD, tansN);
            tansN /= g, tansD /= g;
            
            if (ansN * tansD > ansD * tansN){
                ansN = tansN;
                ansD = tansD;
            }
        }

        for(auto f : adj[a]){
            if(dist2[f] == -1){
                dist2[f] = dist2[a] + 1;
                q.push(f);
            }
        }
    }

    cout << ansN << '/' << ansD << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}