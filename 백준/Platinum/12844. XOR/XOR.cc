#include <bits/stdc++.h>
using namespace std;

int N, sn;
vector<int> A;
vector<int> seg, lazy;

void go_lazy(int l, int r, int n){
    if (lazy[n] != 0){
        if ((r - l) % 2 == 0) seg[n] ^= lazy[n];
        if (l != r) {
            lazy[n*2] ^= lazy[n];
            lazy[n*2+1] ^= lazy[n];
        }
        lazy[n] = 0;
    }
}

void init(int l, int r, int n){
    if (l == r) {
        seg[n] = A[l];
        return;
    }
    int mid = (l+r)/2;
    init(l, mid, n*2);
    init(mid+1, r, n*2+1);
    seg[n] = seg[n*2] ^ seg[n*2+1];
}

void update(int l, int r, int n, int ul, int ur, int v){
    go_lazy(l, r, n);
    
    if (ul > r || ur < l) return;
    if (ul <= l && r <= ur) {
        lazy[n] ^= v;
        go_lazy(l, r, n);
        return;
    }
    
    int mid = (l+r)/2;
    update(l, mid, n*2, ul, ur, v);
    update(mid+1, r, n*2+1, ul, ur, v);
    seg[n] = seg[n*2] ^ seg[n*2+1];
}

int solve(int l, int r, int n, int sl, int sr){
    go_lazy(l, r, n);
    
    if (sl > r || sr < l) return 0;
    if (sl <= l && r <= sr) {
        return seg[n];
    }
    
    int mid = (l+r)/2;
    return solve(l, mid, n*2, sl, sr) ^ solve(mid+1, r, n*2+1, sl, sr);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    
    sn = N*2;
    
    A = vector<int>(N);
    seg = vector<int> (sn*2);
    lazy = vector<int> (sn*2);
    
    for(auto& i : A) cin >> i;
    
    init(0, N-1, 1);
    
    int q;
    cin >> q;
    while(q--){
        
        int t, a, b, c;
        cin >> t;
        if (t == 1){
            cin >> a >> b >> c;
            if (a > b) swap(a, b);
            update(0, N-1, 1, a, b, c);
        }
        else{
            cin >> a >> b;
            if (a > b) swap(a, b);
            
            cout << solve(0, N-1, 1, a, b) << '\n';
        }
    }
}