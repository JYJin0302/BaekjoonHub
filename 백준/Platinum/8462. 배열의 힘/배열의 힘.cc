#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, sn, q;
ll A[100001];
ll cnt[1000001];
ll ans[100001];

ll val = 0;

struct Q{
    ll l, r;
    ll idx;
    
    bool operator<(Q& o){
        if (l/sn == o.l/sn) return r < o.r;
        return l/sn < o.l/sn;
    }
};

void add_num(int ix){
    ll x = A[ix];
    ll c = cnt[x];
    val += (2*c+1)*x;
    cnt[x]++;
}
void sub_num(int ix){
    ll x = A[ix];
    ll c = cnt[x];
    val -= (2*c-1)*x;
    cnt[x]--;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q;
    sn = sqrt(n);
    
    for(int i = 1; i <= n; i++) cin >> A[i];
    
    vector<Q> qry(q);
    for(int i = 0; i < q; i++){
        cin >> qry[i].l >> qry[i].r;
        qry[i].idx = i;
    }
    
    sort(qry.begin(), qry.end());
    
    int cl = qry[0].l, cr = qry[0].r;
    for (int i = cl; i <= cr; i++) add_num(i);
    ans[qry[0].idx] = val;
    
    for (int ix = 1; ix < q; ix++){
        
        int nl = qry[ix].l, nr = qry[ix].r;
        
        while(cr < nr) add_num(cr+1), cr++;
        while(cr > nr) sub_num(cr), cr--;
        
        while(cl < nl) sub_num(cl), cl++;
        while(cl > nl) add_num(cl-1), cl--;
        
        ans[qry[ix].idx] = val;
        
        cl = nl, cr = nr;
    }
    
    for(int i = 0; i < q; i++) cout << ans[i] << '\n';
}