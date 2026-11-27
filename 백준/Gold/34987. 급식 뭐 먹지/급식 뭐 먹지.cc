#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> A(n);
    for(auto&[a,b]: A) cin >> a >> b;


    vector<pair<int,int>> res;
    for(auto[a,b]: A){
        if (a+b > m) continue;
        int l = a, r = m - b;
       //cout << a << ' '<< b << " +> " << l << ' ' << r<< '\n';
        res.push_back(mp(l, 1));
        res.push_back(mp(r+1, -1));
    }
    sort(all(res));

    int mx= 0;
    int ix = 0;
    int cnt = 0;
    while(ix < (int)res.size()){
        int nx = ix;
        while(nx < (int)res.size() && res[nx].x == res[ix].x){
            cnt += res[nx].y;
            nx++;
        }

        mx=  max(mx, cnt);
        ix = nx;
    }
    cout << mx << '\n';


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