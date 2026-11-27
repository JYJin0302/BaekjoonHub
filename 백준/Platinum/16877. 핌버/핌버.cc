#include <bits/stdc++.h>
using namespace std;

vector<int> fib;
vector<int> g;

int solve(int x){
    if (g[x] != -1) return g[x];
    if (x == 0) return g[x] = 0;
    
    vector<int> cnt(16);
    
    for (int i : fib){
        if (i > x) break;
        cnt[solve(x-i)]++;
    }
    
    int idx = 0;
    while(cnt[idx] != 0) idx++;
    return g[x] = idx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a = 1, b = 1, t = 0;
    
    int sz = 3*1e6;
    while(b <= sz){
        t = b;
        b += a;
        a = t;
        fib.push_back(a);
    }
    g = vector<int> (sz+1, -1);
    for(int i = 1; i <= 3*1e6; i++) solve(i);
    
    
    int n;
    cin >> n;
    
    int res = 0;
    while(n--){
        int x;
        cin >> x;
        res ^= solve(x);
    }
    
    if (res == 0) cout << "cubelover";
    else cout << "koosaga";
}