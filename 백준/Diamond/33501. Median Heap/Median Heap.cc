#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

int n;
vector<array<ll, 3>> F[202020];
const ll INF = 1e18;

vector<array<ll, 3>> merge(int a, int b, int c){

    vector<array<ll, 3>> res;
    vector<array<ll, 3>> &V0 = F[a], &V1 = F[b], &V2 = F[c];
    int i0 = 0, i1 = 0, i2 = 0;
    int s0 = (int)V0.size();
    int s1 = (int)V1.size();
    int s2 = (int)V2.size();

    vector<ll> preM0(s0), sufM0(s0);
    vector<ll> preM1(s1), sufM1(s1);
    vector<ll> preM2(s2), sufM2(s2);

    for(int i =0 ;i < s0; i++){
        preM0[i] = min(V0[i][2], (i == 0 ? INF : preM0[i-1]));
    }
    for(int i =0 ;i < s1; i++){
        preM1[i] = min(V1[i][2], (i == 0 ? INF : preM1[i-1]));
    }
    for(int i =0 ;i < s2; i++){
        preM2[i] = min(V2[i][2], (i == 0 ? INF : preM2[i-1]));
    }

    for(int i = s0 - 1; i >= 0; i--){
        sufM0[i] = min(V0[i][2], (i == s0 - 1 ? INF : sufM0[i+1]));
    }
    for(int i = s1 - 1; i >= 0; i--){
        sufM1[i] = min(V1[i][2], (i == s1 - 1 ? INF : sufM1[i+1]));
    }
    for(int i = s2 - 1; i >= 0; i--){
        sufM2[i] = min(V2[i][2], (i == s2 - 1 ? INF : sufM2[i+1]));
    }


    ll pre = -INF;
    while(i0 < s0 && i1 < s1 && i2 < s2){
        ll nxt = V0[i0][1];
        int ni = 0;
        if (nxt > V1[i1][1]) nxt = V1[i1][1], ni = 1;
        if (nxt > V2[i2][1]) nxt = V2[i2][1], ni = 2;

        ll minC = INF;
        minC = min({V0[i0][2] + V1[i1][2], V1[i1][2] + V2[i2][2], V2[i2][2] + V0[i0][2]});
        minC = min({minC, V0[i0][2] + min(preM1[i1] + sufM2[i2], preM2[i2] + sufM1[i1])});
        minC = min({minC, V1[i1][2] + min(preM2[i2] + sufM0[i0], preM0[i0] + sufM2[i2])});
        minC = min({minC, V2[i2][2] + min(preM0[i0] + sufM1[i1], preM1[i1] + sufM0[i0])});

        res.push_back(array<ll, 3>{pre+1, nxt, minC});
        pre = nxt;

        if (ni == 0) i0++;
        else if (ni == 1)i1++;
        else if (ni == 2) i2++;
    }
    return res;

}

void solve(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        ll x, c;
        cin >> x >> c;
        F[i].push_back(array<ll, 3>{-INF, x-1, c});
        F[i].push_back(array<ll, 3>{x, x, 0});
        F[i].push_back(array<ll, 3>{x+1, INF, c});
    }

    for(int i = n/2; i >= 1; i--){
        // merge (i, i*2, i*2+1)
        F[i] = merge(i, i*2, i*2+1);

        // cout << "Record: " << i << " => ";
        // for(auto f: F[i]) cout << f[0] << ' ' << f[1] << ' ' << f[2] << " || ";
        // cout << '\n';
    }


    int q;
    cin >> q;
    while(q--){
        ll x;
        cin >> x;

        int l = 0, r= (int)F[1].size() - 1;
        int ix = -1;
        while(l <= r){
            int md = (l+r)>>1;
            if(F[1][md][0] <= x){
                ix = md;
                l = md + 1;
            }
            else r = md - 1;
        }
        cout << F[1][ix][2] << '\n';
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}
