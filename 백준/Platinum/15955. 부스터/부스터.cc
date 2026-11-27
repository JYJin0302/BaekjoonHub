#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

struct T{
    int v, x, y;
    
    bool operator<(T& o){
        return v < o.v;
    }
};

struct T2{
    int v, x, y, ix;
    
    bool operator<(T2& o){
        return v < o.v;
    }
};


bool cmp_x(pair<int, int>& a, pair<int, int>& b){
    return a.x < b.x;
}
bool cmp_y(pair<int, int>& a, pair<int, int>& b){
    return a.y < b.y;
}

int root[250001];
int find(int n){
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++) root[i] = i;
    
    map<pair<int, int>, int> ix;
    
    vector<pair<int, int>> A(n);
    for(auto& i : A) cin >> i.x >> i.y;
    for(int i = 0; i < n; i++){
        ix[A[i]] = i+1;
    }
    vector<T> B;
    
    sort(A.begin(), A.end(), cmp_x);
    for (int i = 1; i < n; i++){
        B.push_back({A[i].x - A[i-1].x, ix[A[i]], ix[A[i-1]]});
    }
    sort(A.begin(), A.end(), cmp_y);
    for (int i = 1; i < n; i++){
        B.push_back({A[i].y - A[i-1].y, ix[A[i]], ix[A[i-1]]});
    }
    sort(B.begin(), B.end());
    
    
    vector<T2> qry(q);
    for(int i = 0; i < q; i++){
        cin >> qry[i].x >> qry[i].y >> qry[i].v;
        qry[i].ix = i;
    }
    
    sort(qry.begin(), qry.end());
    vector<int> ans(q);
    
    int B_ix = 0, Bs = B.size();
    
    for (auto i : qry){
        
        int a, b, c, d;
        a = i.x, b = i.y;
        c = i.v, d = i.ix;
        
        while(B_ix < Bs && B[B_ix].v <= c){
            int ta, tb;
            ta = B[B_ix].x, tb = B[B_ix].y;
            
            ta = find(ta), tb = find(tb);
            
            if (root[ta] != root[tb]){
                root[ta] = root[tb];
            }
            
            B_ix++;
        }
        
        a = find(a), b = find(b);
        if (a == b) ans[d] = 1;
        else ans[d] = 0;
    }
    
    for (int i = 0; i < q; i++){
        if (ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }
}