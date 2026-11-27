#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >>n;

    vector<ll> pos;
    vector<pair<ll, ll>> A(n);
    ll pv = 0;
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >>a >>b;
        A[i] = {pv+a, b};
        pv += a;
        pos.push_back(pv);
    }

    cin >>m;
    vector<pair<ll, ll>>B(m);
    pv = 0;
    for(int i = 0; i <m; i++){
        ll a,b ;
        cin >>a >>b;
        B[i] = {pv +a, b};
        pv += a;
        pos.push_back(pv);
    }

    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());

    int sn = pos.size();
    vector<ll> nA, nB;

    int ix = 0;
    for(int i = 0; i < n; i++){
        while (ix <sn && pos[ix] < A[i].first){
            nA.push_back(A[i].second);
            ix++;
        }
        nA.push_back(A[i].second);
        ix++;
    }
    ix = 0;
    for(int i = 0; i < m; i++){
        while (ix <sn && pos[ix] < B[i].first){
            nB.push_back(B[i].second);
            ix++;
        }
        nB.push_back(B[i].second);
        ix++;
    }

    //for(int i= 0; i <sn; i++)cout <<nA[i] <<' ' <<nB[i] <<'\n';

    vector<int> res;
    ix = 0;
    while(ix <sn){
        int px = ix;
        int ttx = ix;
        while(ix+1 <sn && nB[ix+1] >= nB[ix]) {
                ix++;
                if(nA[ix] == nB[ix]) ttx = ix;
        }

        //cout <<"CURR: "<< ix << '\n';

        if (nA[ttx] == nB[ix]) ix = ttx;
        res.push_back(ix);
        bool ok = 1;
        ll tmp = nB[ix];
        if (tmp != nA[ix]) ok = 0;
        for(int i = ix-1; i >= px; i--){
            tmp = min(tmp, nA[i]);
            if(nB[i] != tmp) ok = 0;
        }

        int nx = ix;
        tmp = nB[ix];
        while(nx+1 < sn && nB[nx+1] <= nB[nx]) nx++;

        for(int i = ix+1; i <= nx; i++){
            tmp = min(tmp, nA[i]);
            if(nB[i] != tmp) ok = 0;
        }

        if (!ok) {
            cout << -1;
            return 0;
        }
        ix = nx;

        if (ix == sn-1) break;
    }

    ix = 0;
    cout << res.size()<<'\n';
    for(auto i :res){
        i = pos[i];
        while(ix < n && A[ix].first < i) ix++;

        cout <<ix+1 <<' ';
    }

}
