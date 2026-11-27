#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

array<int, 7> P[50505];

vector<int> adj[202020];
int G[202020];
int dfsn[202020];
int ord = 0;
stack<int> stk;
int dfs(int v){
    dfsn[v] = ++ord;
    stk.push(v);
    int ret = dfsn[v];
    for(auto f: adj[v]){
        if (dfsn[f] == -1){
            ret = min(ret, dfs(f));
        }
        else if(G[f] == -1) {
            ret = min(ret, dfsn[f]);
        }
    }

    if (ret == dfsn[v]){
        while(!stk.empty()){
            int a = stk.top(); stk.pop();
            G[a] = v;
            if (a == v) break;
        }
    }
    return ret;
}

int tot = 0;
int inv(int x){
    if (x <= tot) return x + tot;
    return x - tot;
}

void solve(){
    
    int n;
    cin >> n;

    vector<int> D(7);
    vector<int> pD(7);
    for(auto& i : D) cin >> i;
    for(int i =1; i < 7; i++){
        pD[i] = pD[i-1] + D[i-1];
    }
    
    for(auto f: D) tot += f;
    

    for(int i = 0; i < n; i++){
        array<int, 7> rec;
        for(int j = 0; j < 7; j++){
            cin >> rec[j];
            if (rec[j] < 0) {
                rec[j] = inv(-rec[j] + pD[j]);
            }
            else rec[j] += pD[j];
        }
        P[i] = rec;
    }

    int p1, p2;
    cin >> p1 >> p2;

    if (p1 < 0) p1 = inv(-p1 + pD[5]);
    else p1 += pD[5];
    if (p2 < 0) p2 = inv(-p2 + pD[6]);
    else p2 += pD[6];

    // try 1 - 0

    vector<int> res(2 * tot + 10);
    // p1 ok, p2 no
    bool ok = 1;
    for(int i = 0; i < n && ok; i++){
        for(int j =0 ;j < 7; j++){
            int v = P[i][j];
            if (res[v] == 0){
                res[v] = 1;
                res[inv(v)] = -1;
            }
            else if (res[v] == -1){
                ok = 0;
                break;
            }
        }
    }

    // if (ok){
    //     // try Sat Sun
    //     if (res[p1] >= 0 && res[p2] <= 0) {
    //         cout << "possible\n";
    //         return;
    //     }
    //     else if (res[p1] <= 0 && res[p2] >= 0){
    //         cout << "possible\n";
    //         return;
    //     }
    // }

    // try 2 - 0,1

    adj[inv(p1)].push_back(p1);
    adj[inv(p2)].push_back(p2);
    for(int i =0 ;i <  n;i++){
        for(int j =0; j < 7; j++){
            for(int k = j+1; k < 7; k++){
                int v1 = P[i][j];
                int v2 = P[i][k];
                adj[v1].push_back(inv(v2));
                adj[v2].push_back(inv(v1));
            }
        }
    }

    
    memset(dfsn, -1, sizeof dfsn);
    memset(G, -1, sizeof G);
    for(int i =1; i <= 2 * tot; i++){
        if (dfsn[i] == -1){
            dfs(i);
        }
    }

    for(int i =1; i <= tot; i++){
        if (G[i] == G[inv(i)]){
            cout << "impossible\n";
            return;
        }
    }

    cout << "possible\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}