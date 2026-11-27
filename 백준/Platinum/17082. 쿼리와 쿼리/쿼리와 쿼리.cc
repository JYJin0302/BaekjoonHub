#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<ll> A(n);
    for(auto& i : A)cin >> i;
    
    vector<ll> L(m), R(m);
    for(auto& i : L) cin >> i;
    for(auto& i : R) cin >> i;
    
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    
    for (int i = 0; i < m; i++){
        if (L[i] > R[i]){
            while(q--) cout << 1000000000 << '\n';
            return 0;
        }
    }
    
    
    vector<bool> used(n);
    int l = L[0], r = R[0];
    for (int i = 1; i < m; i++){
        int nl = L[i], nr = R[i];
        
        if (nl > r){
            for (int j = l; j <= r; j++) used[j-1] = 1;
            l = nl, r = nr;
        }
        else r = nr;
    }
    for (int i = l; i <= r; i++) used[i-1] = 1;
    
    multiset<ll> ms;
    
    for (int i = 0; i < n; i++){
        if (used[i]) {
            ms.insert(A[i]);
        }
    }
    
    while(q--){
        
        int a, b;
        cin >> a >> b;
        
        a--, b--;
        if (!used[a]) swap(a, b);
        
        if (used[a] && !used[b]){
            
            ms.erase(ms.find(A[a]));
            ms.insert(A[b]);
        }
            
        cout << *ms.rbegin() << '\n';
        swap(A[a], A[b]);
    }
}