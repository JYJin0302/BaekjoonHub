#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

ll segM[606060]; // minimum (A[i] - A[i-1] - A[i+1])
ll lazyM[606060];
ll segS[606060]; // sum (A[i] - A[i-1])

ll fw[606060];


void goLazy(int l, int r, int n){
    if (lazyM[n]){
        segM[n] += lazyM[n];
        if (l != r){
            lazyM[n*2] += lazyM[n];
            lazyM[n*2 + 1] += lazyM[n];
        }
        lazyM[n] = 0;
    }
}

void updateM(int l, int r, int n, int sl, int sr, ll k){
    goLazy(l, r, n);
    if (l > sr || r < sl) return;
    if (l >= sl && r <= sr){
        lazyM[n] += k;
        goLazy(l, r, n);
        //cout << "update M : "<< l << ' '<< r << " : " << k << '\n';
        return;
    }

    int md = (l+r)>>1;
    updateM(l, md, n*2, sl, sr, k);
    updateM(md+1, r, n*2+1, sl, sr, k);
    segM[n] = min(segM[n*2], segM[n*2+1]);
}

ll getM(int l, int r, int n, int sl, int sr){
    goLazy(l, r, n);
    if (l > sr || r < sl) return 100;
    if(l >=sl && r <= sr) return segM[n];
    int md = (l+r)>>1;
    return min(getM(l, md, n*2, sl, sr), getM(md+1, r, n*2+1, sl, sr));
}

void updateS(int l, int r, int n, int ix, ll k){
    if (l > ix || r < ix) return;
    if (l == ix && r == ix){
        segS[n] += k;
        return;
    }

    int md = (l+r)>>1;
    updateS(l, md, n*2, ix, k);
    updateS(md+1, r, n*2+1, ix, k);
    segS[n] = max(0ll, segS[n*2]) + max(0ll, segS[n*2+1]);
}

ll getS(int l, int r, int n, int sl, int sr){
    if (l > sr || r < sl) return 0;
    if (l >=sl && r <= sr) return segS[n];
    int md= (l+r)>>1;
    return max(0ll, getS(l ,md, n*2, sl, sr)) + max(0ll, getS(md+1, r, n*2+1, sl, sr));
}

int n, q;
void updateFW(int ix, ll val){
    while(ix <= n){
        fw[ix] += val;
        ix += ix & -ix;
    }
}

ll getFW(int ix){
    ll res = 0;
    while(ix){
        res += fw[ix];
        ix -= ix & -ix;
    }
    return res;
}


void solve() {
    
    cin >> n >> q;
    while(q--){
        int t;
        cin >> t;
        if (t == 1){
            int l, r, k;
            cin >> l >> r >> k;

            updateFW(l, k);
            updateFW(r+1, -k);

            int tl = max(1, l-1);
            int tr = min(n, r+1);

            // update A[i] - A[i-1] - A[i+1]
            updateM(1, n, 1, tl, tr, +k);
            updateM(1, n, 1, l, l, -k);
            updateM(1, n, 1, r, r, -k);

            // update(A[i] - A[i-1])
            updateS(1, n, 1, l, k);
            updateS(1, n, 1, r+1, -k);
        }
        else{
            int l, r;
            cin >> l >> r;

            // check 
            if (l == r|| getM(1, n, 1, l+1, r-1) < 0){
                cout << -1 << '\n';
                continue;
            }
            if (getFW(l) > getFW(l+1) || getFW(r) > getFW(r-1)){
                cout << -1 << '\n';
                continue;
            }

            ll res = getS(1, n, 1, l+1, r);
            res += getFW(l);

            cout << res << '\n';
        }

        // get state:
        // cout << "STATE: ";
        // for(int i =1; i <= n; i++) cout << getFW(i) << ' ';
        // cout << endl;
        // cout << "MN: ";
        // for(int i =1; i <= n; i++) cout << getM(1, n, 1, i, i) << ' ';
        // cout << endl;
        // cout << "SS: ";
        // for(int i =1; i <= n; i++) cout << getS(1, n, 1, i, i) << ' ';
        // cout << endl;
    }    


    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}