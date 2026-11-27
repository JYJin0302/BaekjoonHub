#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> root;

int find(int n){
    if (n == root[n]) return n;
    return root[n] = find(root[n]);
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    root = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) root[i] = i;
    
    vector<ll> R(n+1, 1);
    
    ll ans1 = 0, ans2 = 0;
    for (int i = 0; i < n-1; i++){
        int x;
        cin >> x;
        
        find(x), find(x+1);
        int a = root[x], b = root[x+1];
        
        ans1 += R[a] * R[b];
        ans2 += R[a] * (R[a] + 1) / 2 * R[b] + R[a] * (R[b] * (R[b] - 1) / 2);
        
        cout << ans1 << ' ' << ans2 << '\n';
        
        R[a] += R[b];
        root[b] = a;
    }
    
}