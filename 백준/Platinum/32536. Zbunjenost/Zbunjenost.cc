#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
int n;
ll seg[555050];

void update(int ix, ll val){
    for(ix += n + 10; ix; ix >>= 1) (seg[ix] += val) %= mod;
}
ll getS(int l, int r){
    ll res = 0;
    for(l += n + 10, r += n + 10; l < r; l >>= 1, r >>= 1){
        if (l & 1) res += seg[l++];
        if (r & 1) res += seg[--r];
        res %= mod;
    }
    return res;
}

bool cmp(pair<int, int>& p1, pair<int, int>& p2){
    if (p1.x != p2.x) return p1.x < p2.x;
    return p1.y > p2.y;
}

vector<int> adj[202020];
ll dp[202020];

ll ans = 1;
void dfs(int v, int pv =-1){
    ll res = 1;
    for(auto f : adj[v]) if (f != pv){
        dfs(f, v);
        res = res * dp[f] % mod;
    }

    dp[v] = res;
    ans = (ans + dp[v]) % mod;
    dp[v] = (dp[v] + 1) % mod;
}


void solve(){
    
    cin >> n;
    vector<pair<int, int>> A;
    for(int i = 0; i < n-3; i++){
        int a,b;
        cin >> a >> b;
        if (a > b ) swap(a, b);
        A.push_back(mp(a, b));
    }

    if(n <= 3){
        cout << 1 << '\n';
        return;
    }
    sort(all(A));

    update(0, 1);
    // ab <= cd <= ef
    for(auto[a,b] : A){
        ll val = getS(0, a+1);
        ans = (ans + val)  % mod;
        update(b, val);
    }

   // cout << "phase 1: " <<ans << '\n';

    // ab <= cd <= "e > f" <= a

    sort(all(A), cmp);
    vector<int> p(n-3, -1);
    stack<int> st;
    for(int i = 0; i < n-3; i++){
        while(!st.empty()){
            auto[a,b] = A[st.top()];
            if (b <= A[i].x) st.pop();
            else break;
        }

        if (!st.empty()){
            p[i] = st.top();
        }
        else p[i] = i;
        st.push(i);
    }

    vector<int> S;
    for(int i =0 ;i < n-3; i++){
        if (p[i] != i) {
            adj[p[i]].push_back(i);
          //  cout << "Adj: " <<p[i] << ' ' << i << '\n';
        }
        else S.push_back(i);
    }
    for(auto f :S){
        dfs(f);
    }

    cout << ans << '\n';



}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int t = 1;
   // cin >> t;
    for(int i =0 ;i < t;i ++){
        solve();
    }


    return 0;
}