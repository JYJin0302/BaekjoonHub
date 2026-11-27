#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b%a, a);
}

bool isP(ll a, ll b){
    ll c = sqrt(a*a + b*b);
    if (a*a + b*b == c*c && gcd(a, b) == 1) return 1;
    return 0;
}

vector<int> adj[201];
int co[201], match[201];


bool dfs(int i){
    if (co[i]) return 0;
    co[i] = 1;
    
    for(auto j : adj[i]) {
        if (match[j] == -1 || dfs(match[j])){
            match[j] = i;
            return 1;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    
    vector<int> A(n), L, R;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        
        A[i] = x;
        if (x % 2 == 0)  L.push_back(x);
        else R.push_back(x);
    }
    
    int sl, sr;
    sl = L.size(), sr = R.size();
    
    for(int i = 0; i < sl; i++){
        for (int j = 0; j < sr; j++){
            if (isP(L[i], R[j])) adj[i].push_back(j);
            
        }
    }
    
    int cnt = 0;
    memset(match, -1, sizeof(match));
    for (int i = 0; i < sl; i++){
        memset(co, 0, sizeof(co));
        cnt += dfs(i);
    }
    cout << cnt;
    
}