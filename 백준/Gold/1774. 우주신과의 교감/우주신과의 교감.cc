#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double dist(pair<ll, ll> a, pair<ll, ll> b){
    return sqrt(powl(a.first - b.first, 2) + powl(a.second - b.second, 2));
}
    
vector<int> root;

int find(int n){
    if(root[n] == n) return n;
    return root[n] = find(root[n]);
}

int main(){
    
    int n, m;
    cin >> n >> m;
    
    cout << fixed << setprecision(2);
    
    root = vector<int>(n+1);
    vector<pair<ll, ll>> A(n+1);
    for(int i = 1; i <= n; i++){
        ll a, b;
        cin >> a >> b;
        A[i] = {a, b};
    }
    
    for(int i = 1; i <= n; i++){
        root[i] = i;
    }
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        find(a), find(b);
        root[root[a]] = root[b];
    }
    
    vector<tuple<double, int, int>> path;
    for (int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++){
            path.push_back({dist(A[i], A[j]), i, j});
        }
    }
    
    sort(path.begin(), path.end());
    
    double ans = 0;
    for(auto i : path){
        double k;
        int a, b;
        tie(k, a, b) = i;
        find(a), find(b);
        if(root[a] == root[b]) continue;
        
        ans += k;
        root[root[a]] = root[b];
    }
    
    cout << ans;
}