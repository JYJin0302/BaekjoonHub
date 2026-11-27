#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define NO {cout << -1 << '\n'; return;}
typedef long long ll;

vector<int> adj[101010];
int topo[101010];
vector<int> idxLst[4];

void solve(){
    
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> cnt(4);
    for(int i = 0; i < n; i++){
        string s1, s2;
        cin >> s1>> s2;

        int idx = (s1 == "set") * 2 + (s2 == "true");
        A[i] = idx;
        cnt[idx]++;
        idxLst[idx].push_back(i);
    }

    // 0 : unset false
    // 1 : unset true
    // 2 : set false
    // 3 : set true

    int m;
    cin >> m;
    vector<pair<int, int>> edg;
    while(m--){
        int a, b;
        cin >> a >> b;
        a--, b--;
        edg.push_back(mp(a, b));
        adj[a].push_back(b);
        topo[b]++;

    }

    if (cnt[1] == 2 || cnt[3] == 2) NO;
    if (cnt[3] == 0 && cnt[1] > 0) NO;

    vector<bool> vis(n);
    vector<int> ans;
    queue<int> q;
    for(int i = 0; i < n; i++){
        if (A[i] == 0 && topo[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()){
        int a=q.front();
        vis[a] = 1;
        q.pop();

        ans.push_back(a);
        for(auto f : adj[a]){
            topo[f]--;
            if (topo[f] == 0 && A[f] == 0) q.push(f);
        }
    }

    if (cnt[3] == 1){
       // cout << "Phase 1\n";
       // for(auto f :ans) cout << f << ' ';
       // cout << '\n';
        int cx = idxLst[3][0];
        if (topo[cx] != 0) NO;
        q.push(idxLst[3][0]);
        for(auto ix : idxLst[2]) if (topo[ix] == 0) q.push(ix);
        while(!q.empty()){
            int a=q.front();
            q.pop();
            vis[a] = 1;

            ans.push_back(a);
            for(auto f : adj[a]){
                topo[f]--;
                if (topo[f] == 0 && A[f] == 2) q.push(f);
            }
        }

        if (cnt[1] == 1){
            
           // cout << "Phase 2\n";
           // for(auto f :ans) cout << f << ' ';
           // cout << '\n';
            int cx = idxLst[1][0];
            if (topo[cx] != 0) NO;
            q.push(cx);
            
            for(auto ix : idxLst[0]) if (!vis[ix] && topo[ix] == 0) q.push(ix);
            while(!q.empty()){
                int a=q.front();
                q.pop();
                vis[a] = 1;

                ans.push_back(a);
                for(auto f : adj[a]){
                    topo[f]--;
                    if (topo[f] == 0 && A[f] == 0) q.push(f);
                }
            }
        }
    }

    if (ans.size() != n) NO;
    for(auto f :ans) cout << f+1 << ' ';
    cout << '\n';

}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    //cin>>tc;
    while(tc--){
        solve();
    }

    return 0;
}