#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;


vector<int>adj[101010];
int ord[101010];
int o;

map<pair<int, int>, bool>used;
void dfs(int v){
    ord[v] = o++;

    int mv = ord[v], mx = -1;
    for(auto i : adj[v]){
        if (ord[i] == -1) {
                used[mp(v, i)] = 1;
                dfs(i);
        }
        else{
            if (ord[i] < mv){
                mv= ord[i];
                mx = i;
            }
        }
    }

    if(mx != -1){
        used[mp(v, mx)] = 1;
    }
}

void solve(){

    int n, m;
    cin >>n >>m;

    used.clear();
    for(int i = 1; i <= n;i ++) {
            adj[i].clear();
            ord[i]= -1;
    }
    o = 0;

    vector<pair<int, int>>edge;
    for(int i = 0; i <m; i++){
        int a, b;
        cin >>a >>b;

        edge.push_back(mp(a, b));
        adj[a].push_back(b);
    }

    dfs(1);

    int cnt = m-2*n;
    for(auto f : edge){
        if (!used[f]){
        cout <<f.first <<' '<<f.second <<'\n';
        cnt--;
        }
        if(cnt == 0)break;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >>t;
    while(t--){

        solve();

    }
}
