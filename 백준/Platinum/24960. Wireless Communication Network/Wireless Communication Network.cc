#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> adj[1001010];
int P[1001010];
int dep[1001010];
int ans = 0;
int dfs(int v){
    dep[v] = 1;
    int ret = 0;
    vector<int> res;
    for(auto f : adj[v]){
        int tmp = dfs(f);
        dep[v] = max(dep[v], dep[f] + 1);
        ret = max(ret, tmp);
        ans = max(ans, dep[f] + tmp);
        res.push_back(dep[f]);
    }
    while((int)res.size() < 2) res.push_back(0);
    if (res[0] < res[1]) swap(res[0], res[1]);
    ans = max(ans, res[0] + res[1]);
    ret = max(ret, res[1]);
    return ret;
}

void solve(){
    int n;
    cin >> n;
    vector<int> H(n);
    for(auto& i : H) cin >> i;


    vector<int> L(n + 1), R(n + 1);
    stack<int> stk;
    for(int f : H){
        while(!stk.empty() && stk.top() < f) stk.pop();
        if (stk.empty()) L[f] = 0;
        else L[f] = stk.top();
        stk.push(f);
    }   
    while(!stk.empty()) stk.pop();

    reverse(all(H));
    for(int f : H){
        while(!stk.empty() && stk.top() < f) stk.pop();
        if (stk.empty()) R[f] = 0;
        else R[f] = stk.top();
        stk.push(f);
    }   

    for( int i =1; i <= n; i++){
        int l = L[i], r =R[i];
        if (l > r) swap(l, r);
        if (l == 0) P[i] = r;
        else P[i] = l;

        if(P[i] == 0) continue;
        adj[P[i]].push_back(i);
    }

    dfs(n);
    cout << ans << '\n';
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}