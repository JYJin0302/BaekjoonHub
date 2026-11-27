#include <bits/stdc++.h>
using namespace std;

int N, M, sn, g = 3;
vector<int> seg;

void init(int l, int r, int n){
    if (l == r){
        if (l > N) seg[n] = 0;
        else seg[n] = 1;
        return;
    }
    
    int mid = (l+r)/2;
    init(l, mid, n*2);
    init(mid+1, r, n*2+1);
    seg[n] = seg[n*2] + seg[n*2+1];
}

void update(int l, int r, int n, int u){
    if (l > u || r < u) return;
    if (l == u && r == u) {
        seg[n] = 0;
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

int solve(int x){
    
    bool left = (x < N/2);
    int l = 0, r = N-1, ans = -1;
    if (left) {
        r = N/2 - 1;
        if (g == 1) r++;
    }
    else {
        l = N/2;
        if (g == 1) l++;
    }
    
    while(l <= r){
        int mid = (l+r)/2;
        int res = 0;
        if (left) {
            res = ssum(0, sn-1, 1, 0, mid);
            if (res >= x + 1){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        else{
            res = ssum(0, sn-1, 1, mid, N-1);
            if (res >= N-x) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
    }
   return ans + 1;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    cin >> N >> M;
    sn = 1;
    while(sn < N) sn *= 2;
    g = 0;
    
    seg= vector<int>(sn*2);
    init(0, sn-1, 1);
    
    while(M--){
        
        int a, b;
        cin >> a >> b;
        b--;
        
        if (a == 1) {
            update(0, sn-1, 1, b);
            if (N%2 == 1 && g == 0) {
                if (b < N/2) g = 1;
                else g = 2;
            }
        }
        else cout << solve(b) << '\n';
    }
    
}