#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1000000;

int N, M, K, ns;

ll mul[MAX_N*4];
ll seg[MAX_N*4];
ll lazy[MAX_N*4];

void init(int l, int r, int n){
    if (l == r) return;
    
    int mid = (l+r)/2;
    
    init(l, mid, n*2);
    init(mid+1, r, n*2+1);
    
    seg[n] = seg[n*2] + seg[n*2+1];
    mul[n] = mul[n*2] + mul[n*2+1];
}

void go_lazy(int l, int r, int n){
    if (lazy[n] != 0){
        seg[n] += lazy[n]*mul[n];
        if (l != r){
            lazy[n*2] += lazy[n];
            lazy[n*2+1] += lazy[n];
        }
        lazy[n] = 0;
    }
}
void update(int l, int r, int n, int ul, int ur, ll v){
    go_lazy(l, r, n);
    
    if (l > ur || r < ul) return;
    if (l >= ul && r <= ur) {
        lazy[n] += v;
        go_lazy(l, r, n);
        return;
    }
    
    int mid = (l+r)/2;
    
    update(l, mid, n*2, ul, ur, v);
    update(mid+1, r, n*2+1, ul, ur, v);
    
    seg[n] = seg[n*2] + seg[n*2+1];
}

ll ssum(int l, int r, int n, int sl, int sr){
    go_lazy(l, r, n);
    
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];
    
    int mid = (l+r)/2;
    return ssum(l, mid, n*2, sl, sr) + ssum(mid+1, r, n*2+1, sl, sr);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M >> K;
    
    ns = 1;
    while(ns < N) ns*=2;
    
    for(int i = 0; i < N; i++){
        cin >> seg[ns + i];
        mul[ns+i] = 1;
    }
    
    init(0, ns-1, 1);
    
    M += K;
    
    while(M--){
        
        int t;
        cin >> t;
        
        ll a, b, c;
        if (t == 1){
            cin >> a >> b >> c;
            update(0, ns-1, 1, a-1, b-1, c);
        }
        else{
            cin >> a >> b;
            cout << ssum(0, ns-1, 1, a-1, b-1) << '\n';
        }
    }
}

