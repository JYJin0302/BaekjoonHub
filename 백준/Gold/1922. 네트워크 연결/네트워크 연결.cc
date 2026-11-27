#include <bits/stdc++.h>
using namespace std;

vector<int> root;

int find(int n){
    if (n == root[n]) return n;
    return root[n] = find(root[n]);
}


int main(){
    
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    
    root = vector<int>(n+1);
    for(int i = 1; i<= n; i++) root[i] = i;
    
    vector<tuple<int, int, int>> A;
    for(int i = 0; i < m ;i++){
        int a, b, c;
        cin >> a >> b>> c;
        A.push_back({c, a, b});
    }
    sort(A.begin(), A.end());
    
    int ans = 0;
    
    for(auto i : A){
        
        int a, b,c;
        tie(a, b, c) = i;
        
        find(b), find(c);
        if (root[b] != root[c]){
            ans += a;
            root[root[b]] = root[c];
        }
    }
    cout << ans;
    
}