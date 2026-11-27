#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n, k;
vector<int> idxLst[101010];

struct D{
    int val, cnt;
    D(){
        val = 0, cnt = 0;
    }
};

D seg[16][303030];

vector<array<int, 4>> Q[5];

void update(int l, int r, int n, int ul, int ur, int val, int ix){
    if(l > ur || r < ul) return;
    if(l >= ul && r <= ur){
        seg[ix][n].cnt += val;
    }
    else{
        int md = (l+r)>>1;
        update(l, md, n*2, ul, ur, val, ix);
        update(md+1, r, n*2+1, ul, ur, val, ix);
    }
    
    if (seg[ix][n].cnt) seg[ix][n].val = r - l + 1;
    else {
        if (l == r) seg[ix][n].val = 0;
        else seg[ix][n].val = seg[ix][n*2].val + seg[ix][n*2+1].val;
    }
}

void solve(){
 
    cin >> n >> k;

    for(int i = 0; i < n;i++){
        int x;
        cin >> x;
        idxLst[x].push_back(i);
    }

    for(int i = 1; i <= n; i++){
        if (idxLst[i].empty()) continue;
        int sn = (int)idxLst[i].size();
        for(int j = 1; j <= k; j++){

            int pre = -1;
            for(int f = 0; f < sn && f + j - 1 < sn; f++){
                int nx = n;
                if (f + j < sn) nx = idxLst[i][j+ f];
                Q[j].push_back(array<int,4>{pre+1, 1, idxLst[i][j + f - 1], nx - 1});
                Q[j].push_back(array<int,4>{idxLst[i][f] + 1, -1, idxLst[i][j + f - 1], nx - 1});

                //cout << "RNage;" << j << " => " << pre+1 << ' '<< idxLst[i][f]  << " <-> " << idxLst[i][j+f-1] << ' '<< nx-1 << '\n';
                pre = idxLst[i][f];
                if (f + j == sn) break;
            }
        }
    }

    for(int i = 1; i <= k; i++){
        sort(all(Q[i]));
    }

    ll ans = 0;
    int ix = 0;
    vector<int> iLst(5);
    while(ix < n){
        for(int j = 1; j <= k; j++){
            while(iLst[j] < (int)Q[j].size() && Q[j][iLst[j]][0] == ix){
                auto val = Q[j][iLst[j]][1];
                auto tL = Q[j][iLst[j]][2];
                auto tR = Q[j][iLst[j]][3];

                // update
                for(int t = 1; t < (1 << k); t++){
                    if (t & (1 << j-1)){
                       // cout << "UPd: " << tL << ' '<< tR << " | " << val << ' ' << t << '\n';
                        update(0, n-1, 1, tL, tR, val, t);
                    }
                }

                iLst[j]++;
            }
        }

        // calculate
        vector<ll> tmp(16);
        for(int i = 1; i < (1 << k); i++){
            tmp[i] = seg[i][1].val;
        }

        vector<ll> tt(16);
        for(int i = 1; i < (1 << k); i++){
            
            int cc = __builtin_popcount(i) % 2;
            int ti = i;
            while(ti){
                if(__builtin_popcount(ti ^ i) & 1){
                    tt[i] -= tt[ti];
                }
                else tt[i] += tt[ti];

                ti = i & (ti - 1);
            }

            if (cc) tt[i] = tmp[i] - tt[i];
            else tt[i] = -tt[i] - tmp[i];
        }
        
        ans += tt[(1 << k) - 1];
        ix++;

    }
    cout << ans << '\n';



}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int t = 1;
   // cin >> t;
    for(int i =0 ;i < t;i ++){
        solve();
    }


    return 0;
}