#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const ll LLINF = 1e18;

bool nope[26][505];
int cntL[26];
int cntR[26];

char ans[505];

struct maxflow{
struct edge{
int u,v;
ll c,f=0;
edge(int u, int v, ll c):u(u),v(v),c(c){}
};
int N,M=0,s,t;
vector<edge> E;
vector<int> level,see;
vector<vector<int>> adj;
queue<int> que;
maxflow(int N):N(N){
level.resize(N); see.resize(N); adj.resize(N);
}
void addEdge(int u, int v, ll c, bool undirected=0){
if (undirected){
E.emplace_back(u,v,c);
E.emplace_back(v,u,c);
}else{
E.emplace_back(u,v,c);
E.emplace_back(v,u,0);
}
adj[u].push_back(M);
adj[v].push_back(M+1);
M+=2;
}
bool bfs(){
fill(level.begin(),level.end(),-1);
que.push(s); level[s]=0;
while(!que.empty()){
int u = que.front(); que.pop();
for (int& e:adj[u]){
    int v = E[e].v;
    if (E[e].c-E[e].f>0 && level[v]==-1){
level[v] = level[u]+1; que.push(v);
}
}
}
return (level[t]!=-1);
}
ll dfs(int u, ll flow){
if (u==t){return flow;}
if (flow==0){return 0;}
for (int& i=see[u]; i<(int)adj[u].size();i++){
int e = adj[u][i];
ll sp = E[e].c- E[e].f;
int v = E[e].v;
if (sp>0 && level[v]==level[u]+1){
ll f = dfs(v,min(flow,sp));
if (f>0){
E[e].f+=f;
E[e^1].f-=f;
return f;
}
}
}
return 0;
}
ll query(int s, int t){
ll ans=0;
this->s = s; this->t = t;
while(bfs()){
fill(see.begin(),see.end(),0);
while(ll flow = dfs(s,LLINF)){
ans+=flow;
}
}
return ans;
}
};

void solve(){
    
    int n, m;
    cin >> n >> m;

    for(int i = 0; i <26; i++){
        cntR[i] = m + 10;
        cntL[i] = 0;
    }

    for(int j =0 ;j < m; j++){
        ans[j] = '?';
    }

    for(int i =0 ;i < n-1; i++){
        string s1, s2;
        cin >> s1 >> s2;

        vector<int> cnt(26);

        for(int j = 0; j < m; j++){
            int v = s1[j] - 'a';
            
            char res = s2[j];
            if (res != 'B') cnt[v]++;
        }

        for(int j = 0; j < m; j++){
            int v = s1[j] - 'a';

            char res = s2[j];
            if (res == 'B'){
                cntR[v] = cnt[v];
                nope[v][j] = 1;
            }
            else if (res == 'G'){
                ans[j] = s1[j];
                nope[v][j] = 1;
            }
            else if(res == 'Y'){
                nope[v][j] = 1;
            }
        }
        for(int j = 0; j < 26; j++){
            cntL[j] = max(cntL[j], cnt[j]);
        }
    }

    for(int i =0; i < m; i++){
        if (ans[i] != '?'){
            int v = ans[i] - 'a';
            cntL[v]--;
            cntR[v]--;
        }
    }

    


    maxflow mf(m + 30);
    int source = 1;
    int sink = 1 + 26 + m + 1;

    int tar = 0;
    for(int i =0; i <26; i++){
        if(cntR[i] == 0) continue;
        tar += cntL[i];
        mf.addEdge(source, 2+i, cntL[i]);
       // cout << "EDG :" << char('a' + i) << " " << cntL[i] << ' ' << cntR[i] << " | ";
        for(int j =0; j < m; j++){

            if(ans[j] == '?' && !nope[i][j]){
                mf.addEdge(i+2, 27 + j + 1, 1);
                //cout << j << ' ';
            }
        }
       // cout << '\n';
    }

    for(int i =0;i < m; i++){
        mf.addEdge(27+i+1, sink, 1);
    }

    int res = mf.query(source, sink);
    //cout << tar << ' '<< res << '\n';

    for(int j = 0; j < 26; j++){
        if(cntL[j] < cntR[j]){
            mf.addEdge(source, j+2, cntR[j] - cntL[j]);
        }
    }
   // cout << ans << '\n';
    res = mf.query(source, sink);

    //cout << tar << ' '<< res << '\n';

    for (auto f : mf.E){
        if (2 <= f.u && f.u <= 27 && 28 <= f.v && f.v <= 27 + m){
            if (f.f == f.c){
                //cout << "Fond: " << f.u << ' ' << f.v << '\n';
                ans[f.v-28] = char('a' + f.u - 2);
            }
        }
    }

    bool ok = 1;
    for(int j =0 ; j < m;j++){
        assert(ans[j] != '?');
    }

    cout << ans << '\n';

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

