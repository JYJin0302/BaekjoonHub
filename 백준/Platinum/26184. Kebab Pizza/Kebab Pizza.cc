#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int root[101010];
int find(int n){
    if (root[n] ==n ) return n;
    return root[n] = find(root[n]);
}

vector<int> adj[101010];
bool vis[101010];
bool onCyc[101010];
int P[101010];

int ccSize = 0;
pair<int ,int> cycD;
void dfs(int v, int pv= -1){
    ccSize++;
    for(auto f: adj[v]){
        if(!vis[f]){
            vis[f] = 1;
            P[f] = v;
            dfs(f, v);
        }
        else if (f != pv){
            // cycle found
            if (cycD.x == -1) {
                cycD = mp(v, f);
            }
        }
    }
}

void solve(){
    
    int n, m;
    cin >> n >> m;

    vector<pair<int ,int>> edg;
    for(int i =0 ;i < n; i++){
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        edg.push_back(mp(a, b));
    }
    sort(all(edg));
    edg.erase(unique(all(edg)), edg.end());

    n = (int)edg.size();

    for(int i = 1;i <= 100000; i++){
        root[i] = i;
    }

    int cycCnt = 0;
    vector<int> lst2;
    vector<bool> ismul2(101010);
    for(auto[a,b]: edg){
        if (a == b) {
            lst2.push_back(a);
            ismul2[a] = 1;
            continue;
        }
        int ta = find(a), tb = find(b);
        if (ta == tb){
            cycCnt++;
        }
        else{
            root[tb] = ta;
        }
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (cycCnt >= 2){
        cout << "impossible\n";
        return;
    }

    for(int i =1;i  <= 100000; i++){
        if (!vis[i] && !adj[i].empty()) {
            vis[i] = 1;
            cycD = mp(-1, -1);
            ccSize = 0;
            dfs(i);

            //cout << "GO dfs: "<< i << " | " << cycD.x << ' ' << cycD.y << '\n';

            if(cycD.x != -1){

                int tCnt = 0;
                for(int cur = cycD.x; ; cur = P[cur]){
                    onCyc[cur] = 1;
                    tCnt++;
                    if(cur == cycD.y) break;
                }
                for(auto f : lst2) {
                    if(onCyc[f]) tCnt++;
                }

                for(int cur = cycD.x; ; cur = P[cur]){
                    for(auto f :adj[cur]){
                        if(onCyc[f]) {}
                        else tCnt++;
                    }
                    if(cur == cycD.y) break;
                }

                if (tCnt == n){
                    cout << "possible\n";
                }
                else{
                    cout << "impossible\n";
                }
                return;

            }
        }
    }


    for(int i = 1; i <= 100000; i++){
        if(adj[i].empty()) continue;

        int cc = 0;
        for(auto f: adj[i]){
            if (adj[f].size() != 1 || ismul2[f]) cc++;
        }

        if(cc > 2){
            cout << "impossible\n";
            return;
        }
    }

    cout << "possible\n";


}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }   
    return 0;
}

