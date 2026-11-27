#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[252525];
int A[252525];

int vis[252525];
int res[252525];
int T = 1;
int getNum(int v, int pv, int dist){
    if (dist == 0) {
        vis[v] = T;
        return 1;
    }
    vis[v] = 0;
    int ret = 0;
    for(auto f: adj[v]) if (f != pv){
        ret += getNum(f, v, dist - 1);
    }
    return ret;
}

void solve(){
    
    int n;
    cin >> n;

    for(int i = 0 ; i <n-1; i++){
        int a, b;
        cin >> a>> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }

    int mn = *min_element(A+1, A+n + 1);

    vector<int> lst;
    for(int i = 1 ; i <= n; i++){
        if (A[i] == mn) lst.push_back(i);
    }
    
    int sz =(int)lst.size();

    memset(vis, -1, sizeof vis);
    if (sz == 1){
        int cent = lst[0];
        
        if(mn == 0){
            vis[cent] = 1;
            res[1] = 1;
        }
        else{
            vis[cent] = 0;
            for(auto f : adj[cent]){
                int c = getNum(f, cent, mn - 1);
                res[T++] = c;
            }
        }
    }
    else{
        int c1 = 0, c2 = 0;
        c1 = getNum(lst[0], lst[1], mn - 1);
        res[T++] = c1;
        c2 = getNum(lst[1], lst[0], mn - 1);
        res[T++] = c2;
    }

    // for(int i = 1; i <= n; i++) cout << vis[i] << ' ';
    // cout << '\n';

    vector<pair<int, int>> r1;
    for(int i = 1; i <= n; i++){
        if (vis[i] > 0) r1.push_back(mp(res[vis[i]], i));
    }
    sort(all(r1));

    for(auto f : r1) cout << f.y << ' ';
    for(int i =1 ; i <= n; i++) if (vis[i] == 0) cout << i << ' ';
    for(int i =1 ; i <= n; i++) if (vis[i] == -1) cout << i << ' ';
    cout << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}