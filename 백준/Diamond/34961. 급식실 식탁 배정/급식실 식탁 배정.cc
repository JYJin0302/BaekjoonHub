#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


int fw[202020];
void update(int ix, int val){
    while(ix <= 200000){
        fw[ix] += val;
        ix += ix & -ix;
    }
}

int getS(int ix){
    int res = 0;
    while(ix){
        res += fw[ix];
        ix -= ix & -ix;
    }
    return res;
}

void solve(){
    
    int q;
    cin >> q;

    multiset<ll> ss;
    ll tot = 0;
    while(q--){
        ll t, x;
        cin >> t>> x;
        if (t == 1){
            tot++;
            update(x, 1);
            ss.insert(x);
        }
        else{
            tot--;
            update(x, -1);
            ss.erase(ss.find(x));
        }

        if (tot == 0){
            cout << 0 << '\n';
            continue;
        }

        ll b = *ss.begin();
        ll ans = 0;
        ll rem = 0;
        ll curX = 0;
        
        auto iter = ss.end();
        ll mx = *(--iter);
        while(curX < tot){
            int tl = b, tr = mx;

            //cout << "CurX:  "<< curX << " | " << tl << ' ' << tr<< endl;
            int tar = 202020;
            while(tl <= tr){
                int md = (tl+tr)>>1;
               // cout << "search: " << md << ' ' << getS(md) << endl;
                if (getS(md) > curX) {
                    tar = md;
                    tr = md -1;
                }
                else tl = md + 1;
            }

            //cout << "TA: " << tar << endl;
            if (tar > mx) break;

            ll cur = getS(tar) - curX;
            ll ansCnt = (cur + tar - 1) / tar;
           // cout << "ans add: " << ansCnt << ' ' << cur << ' ' << tar << endl;
            ans += ansCnt;
            curX += ansCnt * tar;
            b = tar + 1;
        }

        cout << ans << '\n';


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
