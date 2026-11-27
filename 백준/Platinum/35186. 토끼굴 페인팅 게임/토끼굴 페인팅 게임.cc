#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[101010];
int sz[101010];
int D[101010];
int depth[101010];
int spt[18][101010];

void dfs(int v){
    D[v] = 0;
    sz[v] = 1;
    for(auto f :adj[v]){
        depth[f] = depth[v] + 1;
        spt[0][f] = v;
        dfs(f);
        D[v] = max(D[v], D[f] + 1);
        sz[v] += sz[f];
    }
}

vector<int> lst[101010];
int topo[101010];

void solve(){
    
    int n;
    cin >> n;

    for(int i =2; i <= n; i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    dfs(1);

    for(int i =1 ;i <= n; i++){
        if (sz[i] == n/2){
            cout << D[i] + 1 << '\n';
            return;
        }
    }

    for(int j = 1; j < 18; j++){
        for(int i = 1; i <= n; i++){
            spt[j][i] =spt[j-1][spt[j-1][i]];
        }
    }


    // 답 최대 2
    for(int i = 1; i <= n; i++){
        lst[sz[i]].push_back(i);
    }

    for(int i =2; i <= n; i++){
        int p = spt[0][i];
        int cur = sz[i];
        if(cur >= n/2) continue;

        int nd = n/2 - cur;
        for(auto f: lst[nd]){
            // check child
            int dif = depth[f] - depth[i];
            int tmpF = f;
            for(int j =0; j < 18; j++){
                if (dif & (1 << j)){
                    tmpF = spt[j][tmpF];
                }
            }

            if(tmpF == i) continue;
            cout << 2 << '\n';
            return;
        }
    }

    cout << 0 << '\n';
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