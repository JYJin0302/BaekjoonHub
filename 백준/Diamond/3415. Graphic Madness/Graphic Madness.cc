
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int K,N,M;
vector<int>adj[4040];
int nxt[4040], prv[4040];
bool ok = 1;
void dfs(int v, int pv = -1){

    int cnt = 0;
    vector<int> tmp;
    for(auto i : adj[v]) if(i != pv){
        dfs(i, v);
        if(nxt[i] == -1){
            nxt[i] = v;
            cnt++;
            tmp.push_back(i);
        }
    }

    if(cnt==0){
        if (v < N) ok = 0;
        if (v >= N+K && v < N+K+M) ok = 0;
        return;
    }
    if(cnt > 2){
        ok = 0;
        return;
    }

    if (cnt == 1){
        prv[v] = tmp[0];
    }
    else{
        prv[v] = tmp[0];
        nxt[v] = tmp[1];
    }
}

void solve(){
    cin>>K>>N>>M;

    ok = 1;
    for(int i = 0; i < N+M+K*2 + 10; i++) {
        adj[i].clear();
        nxt[i] = -1;
        prv[i] = -1;
    }

    // A
    for (int i=0;i<N+K-1;i++){
        string s,t; cin>>s>>t;
        int u,v; u=v=0;
        if (s[1]=='S'){
            u+=N;
        }
        int x = stoi(s.substr(2));
        u += x-1;

        if (t[1]=='S'){
            v+=N;
        }
        x = stoi(t.substr(2));
        v+=x-1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // B
    for (int i=0;i<M+K-1;i++){
        string s,t; cin>>s>>t;
        int u,v; u=v=N+K;
        if (s[1]=='S'){
            u+=M;
        }
        int x = stoi(s.substr(2));
        u += x-1;

        if (t[1]=='S'){
            v+=M;
        }
        x = stoi(t.substr(2));
        v+=x-1;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    vector<int> conn(N+M+K*2+10);
    // leaf connection
    for (int i=0;i<K;i++){
        string s,t; cin>>s>>t;
        int u,v; u=v=N;
        if (s[0]=='B'){u = N+M+K;}
        if (t[0]=='B'){v = N+M+K;}

        int x = stoi(s.substr(2));
        u+=x-1;
        x = stoi(t.substr(2));
        v+=x-1;
        //adj[u].push_back(v);
        //adj[v].push_back(u);

        conn[u] = v;
        conn[v] = u;
    }

    dfs(0);
    if (!ok){
        cout << "NO\n";
        return;
    }

    dfs(N+K);
    if (!ok){
        cout << "NO\n";
        return;
    }

    for(int i = N; i <N+K; i++){
        if (prv[i] != -1) continue;

        int ix = i;
        while(1){
            int nx = nxt[ix];
            if (nx == -1) break;
            if (prv[nx] == ix) {}//ok
            else {
                swap(prv[nx], nxt[nx]);
            }
            ix = nx;
        }
    }

    for(int i = N+K+M; i <N+K*2+M; i++){
        if (prv[i] != -1) continue;

        int ix = i;
        while(1){
            int nx = nxt[ix];
            if (nx == -1) break;
            if (prv[nx] == ix) {}//ok
            else {
                swap(prv[nx], nxt[nx]);
            }
            ix = nx;
        }
    }

    // path complete
    int sx = N, pv = -1;
    bool dir = 0;
    vector<int>ans = {N};
    vector<bool> vs(N+M+K*2+10);
    vs[N] = 1;

    if (nxt[sx] == -1) dir= 0;
    else dir = 1;
    while(ans.size() < N+M+2*K){
        int currx = sx;
        while(dir && nxt[sx] != -1){
            sx = nxt[sx];
            ans.push_back(sx);
        }
        while(!dir && prv[sx] != -1){
            sx = prv[sx];
            ans.push_back(sx);
        }

        int nx = conn[sx];
        if (!vs[nx]){
            sx = nx;
            ans.push_back(sx);

            if(nxt[sx] == -1) dir = 0;
            else dir = 1;
        }
        else break;
    }

    if (ans.size() != N+M+K*2) {
        cout << "NO\n";
        return;
    }
    cout <<"YES ";
    for(auto i :ans){
        if (i >= N+K) {
                cout <<'B';
                i -= N+K;

                if(i >= M) {
                        cout << 'S';
                        i -= M;
                }
                else cout << 'P';
                cout <<i+1 << ' ';
        }
        else {
                cout <<'A';
                if (i >= N) {
                    cout << 'S';
                    i -= N;
                }
                else cout <<'P';
                cout <<i+1 << ' ';
        }
    }
    cout <<'\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >>t;
    while(t--){
        solve();
    }
}

