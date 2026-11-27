#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

int n;
int seg[2002020];
void update(int ix, int val){
    for(ix += n + 10; ix; ix >>= 1){
        seg[ix] = min(seg[ix], val);
    }
}

int getMin(int l, int r){
    int res = 1e7;
    for(l += n+10, r += n+10; l < r; l>>=1, r>>= 1){
        if (l &1) res = min(res, seg[l++]);
        if (r&1) res = min(res, seg[--r]);
    }
    return res;
}

int fw[3003030];
void upd(int ix ,int val){
    while(ix <= n){
        fw[ix] += val;
        ix += ix & -ix;
    }
}

int getRes(int ix){
    int res = 0;
    while(ix){
        res += fw[ix];
        ix -= ix & -ix;
    }
    return res;
}



void solve(){
    
    cin >> n;

    vector<int> A(n+1);
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }

    vector<int> pos(n + 1);
    vector<int> pre(n+1);
    for(int i = 1; i <= n; i++){
        pre[i] = pos[A[i]];
        pos[A[i]] = i;
    }

    for(int i = 1; i <= n*2 + 100; i++) seg[i] = 1e7;
    for(int i = 1; i <= n; i++) update(i, A[i]);

    vector<pair<int, int>> res;
    for(int i = 1; i <= n; i++){
        if (pre[i]){
            int x = getMin(pre[i], i);
            if(x == A[i]){
                //cout << "Found: " << i << ' ' << pre[i] << '\n';
                res.push_back(mp(pre[i], i));
                upd(i, 1);
            }
        }
    }
    sort(all(res));

    int q;
    cin >> q;
    
    vector<array<int, 3>> qur;
    for(int i = 0; i < q; i++){
        int l,  r;
        cin >> l >> r;
        qur.push_back({l,r, i});
    }
    sort(all(qur));

    vector<int> ans(q);
    int idx= 0;
    for(int i = 0; i < q; i++){
        auto[l, r, ix] = qur[i];
        //cout << "Go: " << l << ' ' << r << ' ' << ix  << '\n';
        while(idx < (int)res.size() && res[idx].x < l){
            upd(res[idx].y, -1);
            idx++;
        }

        int res = getRes(r) - getRes(l-1);

        ans[ix] = r - l + 1 - res;
    }

    for(auto f: ans) cout <<f << '\n';


}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}