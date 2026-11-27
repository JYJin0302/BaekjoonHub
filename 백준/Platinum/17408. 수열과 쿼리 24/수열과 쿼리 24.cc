#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


pair<int, int> seg[303030];

pair<int, int> operator+(pair<int, int> p1, pair<int, int> p2){
    pair<int, int> res;
    if (p1.x > p2.x){
        res.x = p1.x;
        swap(p1.x, p1.y);
    }
    else{
        res.x = p2.x;
        swap(p2.x, p2.y);
    }
    res.y = max(p1.x, p2.x);
    return res;
}

void update(int l, int r, int n, int ix, int val){
    if (l > ix || r < ix) return;
    if (l == ix && r == ix){
        seg[n] = mp(val, 0);
        return;
    }

    int md = (l+r)>>1;
    update(l, md, n*2, ix, val);
    update(md+1,r, n*2+1, ix, val);
    seg[n] = seg[n*2] + seg[n*2+1];
}

pair<int, int> getS(int l, int r, int n, int sl, int sr){
    if (l > sr || r < sl) return mp(0, 0);
    if(l >= sl && r <= sr) return seg[n];

    int md = (l+r)>>1;
    return getS(l, md, n*2, sl, sr) + getS(md+1,r ,n*2+1, sl, sr);
}

void solve(){
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        update(0, n-1, 1, i, x);
    }

    int q;
    cin >> q;
    while(q--){
        int t, l, r;
        cin >> t >> l >> r;
        if (t ==1){
            l--;
            update(0, n-1, 1, l, r);
        }
        else{
            l--, r--;
            auto res = getS(0, n-1, 1, l, r);
            cout << res.x + res.y << '\n';
        }
    }

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}