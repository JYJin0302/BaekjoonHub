#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<ll> seg;

void init(int l, int r, int n){
    if(l == r) return;

    int m = (l+r)>>1;
    init(l, m, n*2);
    init(m+1, r, n*2+1);
    seg[n] = min(seg[n*2], seg[n*2+1]);
}

void update(int l, int r, int n, int u, int v){
    if(l > u || r <u) return;
    if (l == u && r == u){
        seg[n] += v;
        return;
    }

    int m = (l+r)>>1;
    update(l, m, n*2, u, v);
    update(m+1, r, n*2+1, u, v);
    seg[n] = min(seg[n*2], seg[n*2+1]);
}


ll getMin(int l, int r, int n, int sl, int sr){
    if (l > sr || r < sl) return 1e8;
    if (l>= sl && r <= sr){
        return seg[n];
    }

    int m = (l+r)>>1;
    return min(getMin(l, m, n*2, sl, sr), getMin(m+1, r, n*2+1, sl, sr));

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    vector<ll> A(n);
    for(auto&i :A) cin >> i;

    int sn = 1;
    while(sn < n) sn*= 2;
    seg = vector<ll>(sn*2);

    for(int i = 0; i < n; i++) seg[i+sn] = A[i];
    for(int i = n; i< sn; i++) seg[i+sn] = 1e8;

    init(0, sn-1, 1);

    ll ans = A[0], pv = A[0];
    for(int i =1 ; i < n;i ++){
        pv = min(pv, A[i]);
        ans += pv;
    }

    cout << ans <<'\n';

    int q;
    cin >> q;
    while(q--){

        int a, b;
        cin >> a>> b;
        if(a == 1){
            if (b != 0 && getMin(0, sn-1, 1, 0, b-1) <= A[b]){
                update(0, sn-1, 1, b, 1);
                A[b]++;
            }
            else{
                A[b]++;
                int l = b+1, r = n-1, res = b;
                while(l <= r){
                    int m = (l+r)>>1;

                    //cout << "curr: "<< l <<' '<< r<<' ' <<m << ' ';
                    if (getMin(0, sn-1, 1, b+1, m) >= A[b]) {
                        res = m;
                        l = m+1;
                    //cout << "ok\n";
                    }
                    else {
                            r = m-1;
                           // cout <<"no\n";
                    }

                }
                ans += res-b+1;
                //cout <<"RES:"<< res << '\n';

                update(0, sn-1, 1, b, 1);
            }
        }
        else{
            if (b != 0 && getMin(0, sn-1, 1, 0, b-1) < A[b]){
                update(0, sn-1, 1, b, -1);
                A[b]--;
            }
            else{

                int l = b+1, r = n-1, res = b;
                while(l <= r){
                    int m = (l+r)>>1;

                    //cout << "curr: "<< l <<' '<< r<<' ' <<m << ' ';
                    if (getMin(0, sn-1, 1, b+1, m) >= A[b]) {
                        res = m;
                        l = m+1;
                    //cout << "ok\n";
                    }
                    else {
                            r = m-1;
                            //cout <<"no\n";
                    }

                }
                ans -= res-b+1;

                //cout << "res:"<< res <<'\n';
                update(0, sn-1, 1, b, -1);
                A[b]--;
            }
        }

        cout << ans <<'\n';
    }
    
}
