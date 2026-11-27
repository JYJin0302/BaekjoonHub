#include <bits/stdc++.h>
using namespace std;

int n, m, sn;

vector<int> seg;
vector<bool> lazy;

void go_lazy(int l, int r, int n){
    if (lazy[n]){
        int d = r - l + 1;
        seg[n] = d - seg[n];
        
        if (l != r){
            lazy[n*2] = !lazy[n*2];
            lazy[n*2+1] = !lazy[n*2+1];
        }
        lazy[n] = 0;
    }
}

void update(int l, int r, int n, int ul, int ur){
    go_lazy(l, r, n);
    
    if (l > ur || r < ul) return;
    if (l >= ul && r <= ur) {
        lazy[n] = 1;
        go_lazy(l, r, n);
        return;
    }
    
    int mid = (l+r)/2;
    update(l, mid, n*2, ul, ur);
    update(mid+1, r, n*2+1, ul, ur);
    
    seg[n]= seg[n*2] + seg[n*2+1];
}

int ssum(int l, int r, int n, int sl, int sr){
    go_lazy(l, r, n);
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];
    
    int mid = (l+r)/2;
    return ssum(l, mid, n*2, sl, sr) + ssum(mid+1, r, n*2+1, sl, sr);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    sn = 1;
    while(sn < n) sn *= 2;
    seg = vector<int>(sn*2);
    lazy = vector<bool>(sn*2);
    
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        
        b--, c--;
        if (a == 0) update(0, sn-1, 1, b, c);
        else cout << ssum(0, sn-1, 1, b, c) << '\n';
    }
}