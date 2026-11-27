#include <bits/stdc++.h>
using namespace std;

vector<int> seg;

void init(int l, int r, int n){
    if (l == r) return;
    
    int mid = (l+r)/2;
    init(l, mid ,n*2);
    init(mid+1, r, n*2+1);
    seg[n] = seg[n*2] + seg[n*2+1];
}

void update(int l, int r, int n, int u){
    if (l > u || r < u) return;
    if (l == u && r == u) {
        seg[n] = 1 - seg[n];
        return;
    }
    
    int mid = (l+r)/2;
    update(l, mid, n*2, u);
    update(mid+1, r, n*2+1, u);
    seg[n] = seg[n*2] + seg[n*2+1];
}

int ssum(int l, int r, int n, int sl, int sr){
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];
    
    int mid = (l+r)/2;
    return ssum(l, mid, n*2, sl, sr) + ssum(mid+1, r, n*2+1, sl, sr);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int s = 1;
    while(s < n) s *= 2;
    
    seg = vector<int> (s*2);
    
    for(int i = 0; i < n; i++){
        cin >> seg[s + i];
        seg[s+i] %= 2;
    }
    
    init(0, s-1, 1);
    
    int q;
    cin >> q;
    while(q--){
        
        int a, b, c;
        cin >> a >> b >> c;
        
        if (a == 1){
            b--;
            if (seg[s + b] != c % 2) update(0, s-1, 1, b);
        }
        else {
            b--, c--;
            int ss = ssum(0, s-1, 1, b, c);
            if (a == 2) cout << c - b + 1 - ss << '\n';
            else cout << ss << '\n';
        }
    }
}