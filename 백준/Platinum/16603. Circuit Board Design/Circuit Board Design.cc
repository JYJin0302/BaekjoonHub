#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
long double xpos[1001], ypos[1001];

long double cnt = 0;
void dfs(int v, int pv = -1){
    //cout <<"CURR:"<<v <<' ' <<cnt <<' ' <<xpos[v] <<' ' <<ypos[v] <<'\n';
    int tc = 0;
    for(int i = 0; i < adj[v].size(); i++){
        int nv = adj[v][i];
        if (nv == pv)continue;
        if(tc != 0) cnt += 1;
        tc++;
        xpos[nv] = xpos[v] + cos(cnt/1000*3.141592);
        ypos[nv] = ypos[v] + sin(cnt/1000*3.141592);
        dfs(nv, v);
    }

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout <<fixed <<setprecision(10);

    int n;
    cin >>n;
    for(int i = 0; i <n-1; i++){
        int a, b;
        cin >> a >>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    for(int i = 1; i <= n; i++){
        cout << xpos[i] <<' ' << ypos[i] << '\n';
    }
}
