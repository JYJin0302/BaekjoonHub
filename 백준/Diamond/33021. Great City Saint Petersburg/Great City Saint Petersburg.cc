#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

struct D{
    ll val, mx;
    D(int v = 0){
        val = v, mx = v;
    }

    D operator+(D& o) const {
        D res;
        res.mx = max(mx, o.mx);
        res.val  = val + o.val;
        return res;
    }
};

ll iA[202020];
int A[202020];
D segB[606060], segW[606060];
pair<ll, ll> lazyB[606060], lazyW[606060]; // Add or set

void goLazy(int l, int r, int n, D seg[], pair<ll, ll> lazy[]){
    if (lazy[n] != mp(1ll, 0ll)){
        if (!lazy[n].x){
            seg[n] = 0;
        }
        seg[n].val += 1ll * (r - l + 1) * lazy[n].y;
        seg[n].mx += lazy[n].y;

        if (l != r){
            lazy[n*2] = mp(lazy[n*2].x * lazy[n].x, lazy[n*2].y*lazy[n].x + lazy[n].y);
            lazy[n*2+1] = mp(lazy[n*2+1].x * lazy[n].x, lazy[n*2+1].y*lazy[n].x + lazy[n].y);
        }
        lazy[n] = mp(1, 0);
    }
}

void init(int l, int r, int n){
    lazyB[n] = lazyW[n] = mp(1, 0);
    if (l == r){
        segB[n] = A[l];
        segW[n] = iA[l];
        return;
    }
    int md = (l+r)>>1;
    init(l, md, n*2);
    init(md+1, r, n*2+1);
    segB[n] = segB[n*2] + segB[n*2+1];
    segW[n] = segW[n*2] + segW[n*2+1];
}

void update(int l, int r, int n, int ul, int ur, int t, int val, D seg[], pair<ll, ll> lazy[]){
    goLazy(l, r, n, seg, lazy);
    if (l > ur || r < ul) return;
    if (l >= ul && r <= ur){
        lazy[n] = mp(t, val);
        goLazy(l, r, n, seg, lazy);
        return;
    }

    int md = (l+r)>>1;
    update(l, md, n*2, ul, ur, t, val, seg, lazy);
    update(md + 1, r, n*2 + 1, ul, ur, t, val, seg, lazy);
    seg[n] = seg[n*2] + seg[n*2+1];
}

int getMax(int l, int r, int n, int sl, int sr){
    // block에서만 시행
    goLazy(l, r, n, segB, lazyB);
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr){
        return segB[n].mx;
    }

    int md = (l+r)>>1;
    return max(getMax(l, md, n*2, sl, sr), getMax(md + 1, r, n*2+1, sl, sr));
}

// void pf(int l, int r, int n){
//     goLazy(l, r, n, segW, lazyW);
//     goLazy(l, r, n, segB, lazyB);
//     if (l == r){
//         cout << "idx: " << l << " => " << segW[n].val << ' ' << segB[n].val << " || ";
//         return;
//     }
//     int md = (l+r)>>1;
//     pf(l, md, n*2);
//     pf(md+1, r, n*2+1);
// }


int getLeftMost(int l, int r, int n, int sl, int sr, int val){ // val 이상, 가장 왼쪽
    goLazy(l, r, n, segB, lazyB);
    if (l > sr || r < sl || segB[n].mx < val) return -1;

    if (l == r) return l;
    int md =(l+r)>>1;
    int res = getLeftMost(l, md, n*2, sl, sr, val);
    if (res != -1){
        return res;
    }
    return getLeftMost(md+1, r, n*2+1, sl, sr, val);
}

int getRightMost(int l, int r, int n, int sl, int sr, int val){ // val 이상, 가장 오른쪽
    goLazy(l, r, n, segB, lazyB);
    if (l > sr || r < sl || segB[n].mx < val) return -1;

    if (l == r) return l;
    int md =(l+r)>>1;
    int res = getRightMost(md+1, r, n*2+1, sl, sr, val);
    if (res != -1){
        return res;
    }
    return getRightMost(l, md, n*2, sl, sr, val);
}

void solve(){
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) cin >> A[i];


    vector<int> Lmax(n), Rmax(n);
    for(int i = 0; i < n; i++){
        Lmax[i] = A[i];
        if(i) Lmax[i] = max(Lmax[i-1], A[i]);
    }
    for(int i = n-1; i >= 0; i--){
        Rmax[i] = max(A[i], i == n-1 ? 0 : Rmax[i+1]);
    }


    for(int i =0 ; i < n; i++){
        iA[i] = min(Lmax[i], Rmax[i]);
    }

    init(0, n-1, 1);

    cout << segW[1].val - segB[1].val << '\n';

    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;


        update(0, n - 1, 1, l, r, 1, 1, segB, lazyB);

        int Lmax = 0, Rmax = 0;
        if (l){
            Lmax = getMax(0, n-1, 1, 0, l-1);
        }
        if (r != n-1) {
            Rmax = getMax(0, n-1, 1, r+1, n-1);
        }
        int Mmax = getMax(0, n-1, 1, l, r);

        int uLx = l, uRx = r;
        if (Mmax <= min(Lmax, Rmax)){
            // no op
        }
        else{
            // 각 방향으로 Mmax 이상의 index 찾기
            int ldx = -1, rdx = n;
            uLx = getLeftMost(0, n-1, 1, l, r, Mmax);
            uRx = getRightMost(0, n-1, 1, l, r, Mmax);

            if(Lmax >= Mmax){
                uLx = getRightMost(0, n-1, 1, 0, l-1, Mmax) + 1;
            }
            else{
                uLx = getLeftMost(0, n-1, 1, l, uLx, Lmax+1);
            }

            if(Rmax >= Mmax){
                uRx = getLeftMost(0, n-1, 1, r+1, n-1, Mmax) - 1;
                
            }
            else{
                uRx = getRightMost(0, n-1, 1, uRx, r, Rmax+1);                
            }
            
            update(0, n- 1, 1, uLx, uRx, 1, 1, segW, lazyW);
           // cout << "upd: " << uLx << ' ' << uRx << '\n';
        }


        cout << segW[1].val - segB[1].val << '\n';

        // print state
       // pf(0, n-1, 1);
        //cout << endl;

    }


}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}