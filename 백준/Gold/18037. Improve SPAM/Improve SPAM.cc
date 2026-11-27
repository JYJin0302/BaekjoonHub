#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int>adj[2010];
const ll mod = 1e9+7;

ll dp[2010];
int topo[2010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, l;
    cin >>n >>l;

    for(int i = 1; i <= l; i++){
        int t;
        cin >>t;
        while(t--){
            int x;
            cin >>x;

            adj[i].push_back(x);
            topo[x]++;
        }
    }

    dp[1] = 1;
    queue<int>q;
    for(int i= 2; i <= n; i++) if(topo[i] == 0)q.push(i);
    while(!q.empty()){
        int a =q.front();
        q.pop();

        for(auto i :adj[a]){
            topo[i]--;
            if (topo[i] == 0 && i != 1) q.push(i);
        }

    }
    int cnt = 0;
    ll ans = 0;

    q.push(1);
    while(!q.empty()){
        int a =q.front();
        q.pop();

        for(auto i :adj[a]){
            dp[i] = (dp[i] +dp[a])% mod;
            topo[i]--;
            if (topo[i] == 0) q.push(i);
        }
        if(adj[a].empty()){
            cnt++;
            ans = (ans+ dp[a])%mod;
        }

    }
    cout << ans << ' ' <<cnt;
}