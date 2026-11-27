#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if (a >b)swap(a, b);
    if (a == 0)return b;
    return gcd(b%a, a);
}

vector<ll>seg;

void init(int l, int r, int n){
    if(l == r)return;
    int m =(l+r)>>1;
    init(l, m, n*2);
    init(m+1, r, n*2+1);
    seg[n] = gcd(seg[n*2], seg[n*2+1]);
}

ll getS(int l, int r, int n, int sl, int sr){
    if (l >sr || r <sl)return 0;
    if (l >= sl &&r <= sr)return seg[n];

    int m = (l+r)>>1;
    return gcd(getS(l, m, n*2, sl, sr), getS(m+1, r, n*2+1, sl, sr));
}

int getIdx(int l, int r, int n, ll val, int k){

    if (l >= k){
        if (seg[n] % val == 0){
            return -1;
        }
        if (l == r) return l;
        
        int md = (l+r)>>1;
        if (seg[n*2] % val == 0) return getIdx(md+1, r, n*2+1, val, k);
        return getIdx(l, md, n*2, val, k);
    }

    if (l == r || r < k) return -1;
    int md = (l+r)>>1;

    int res = -1;
    if (md >= k) res = getIdx(l, md, n*2, val, k);
    if (res != -1)return res;

    return getIdx(md+1, r, n*2+1, val, k);
}

void solve(){

    int n;
    cin >>n;
    vector<ll>A(n);
    for(auto&i :A)cin >>i;

    int sn = 1;
    while(sn <n)sn*= 2;

    seg= vector<ll> (sn*2);

    for(int i = 0; i < n; i++){
        seg[sn+i] = A[i];
    }

    init(0, sn-1, 1);

    ll ans = n;
    for(int i = 0; i < n; i++){

        //cout <<"CUrr:"<< i <<'\n';
        ll currG = A[i];
        ll currix = getIdx(0, sn-1, 1, currG, i);
        if (currix == -1) currix = n-1;
        else currix--;
        //ll currix = i;
        //ll l = currix+1, r = n-1;
        //while(l <= r){
        //    ll md = (l+r)>>1;

        //    if(getS(0, sn-1, 1, i, md) == currG) {
        //        l = md+1;
        //        currix = md;
        //    }
        //    else r = md-1;
        //}
        ans = max(ans, A[i]*(currix-i+1));
        currix++;

    //cout <<currix <<'\n';

        while(currix < n){

            //cout << currix << ' ' << ans <<'\n';
            ll newG = gcd(currG, A[currix]);
            ll diff = currG / newG;
            ll nextix = currix + (currix-i)*(diff-1);

            if (nextix > n || getS(0, sn-1, 1, i, nextix-1) != newG)break;
            currix = nextix-1;
            currG = newG;

            currix  = getIdx(0, sn-1, 1, newG, currix);
            if (currix == -1) currix = n-1;
            else currix--;
            //l = currix, r = n-1;
            //while(l <= r){
            //    ll md = (l+r)>>1;

            //    if(getS(0, sn-1, 1, i, md) == currG) {
            //        l = md+1;
            //        currix = md;
            //    }
            //    else r = md-1;
            //}
            ans = max(ans, newG*(currix-i+1));
            currix++;
        }

    }
    cout <<ans <<'\n';



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
}
