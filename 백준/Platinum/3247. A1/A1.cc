#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){

    int m, n;
    cin >> m >> n;

    vector<int> A(n);
    for(auto& i : A) cin >> i;

    vector<pair<int, int>> res;

    for(int i =1; i < n; i++){
        int l = A[i-1];
        int r = A[i];
        if (r-l >= m){
            res.push_back(mp(1, 1));
            res.push_back(mp(m+1, -1));
        }
        else{
            int tl = (r + 1) % m;
            if (tl == 0) tl = m;
            int tr = l % m;
            if (tr == 0) tr = m;

           // cout << "Found: " << tl << ' ' << tr << '\n';
            if (tl <= tr){
                res.push_back(mp(1, 1));
                res.push_back(mp(tl, -1));
                res.push_back(mp(tr + 1, 1));
                res.push_back(mp(m+1, -1));
            }
            else{
                res.push_back(mp(tr + 1, 1));
                res.push_back(mp(tl, -1));
            }
        }
    }
    
    res.push_back(mp(1, 1));
    res.push_back(mp(m+1,-1));
    sort(all(res));

    int ix = 0;
    int val = 0;
    int mn = n;
    while(ix < (int)res.size()){
        //cout << "go :" << ix << '\n';
        int nx = ix;
        if (res[ix].x > m) break;
        while(nx < (int)res.size() && res[nx].x == res[ix].x){
            //cout << res[nx].x << ' ' << res[nx].y << " | ";
            val += res[nx].y;
            nx++;
        }
        //cout << '\n';
        mn = min(mn,val);
        ix = nx;
    }

    cout << mn << '\n';
    ix = 0;
    val = 0;
    int pre = 1;
    while(ix < (int)res.size()){
        int nx = ix;
        if (val == mn){
            while(pre < res[ix].x){
                cout << pre++ << ' ';
            }
        }
        pre = res[ix].x;
        if (res[ix].x > m) break;

        while(nx < (int)res.size() && res[nx].x == res[ix].x){
            val += res[nx].y;
            nx++;
        }
        mn = min(mn,val);
        ix = nx;
    }
    cout << '\n';
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