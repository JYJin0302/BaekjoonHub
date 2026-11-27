#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){
    
    int n, l, w;
    cin >> n >> w >> l;

    vector<pair<int, int>> A(n);
    for(auto& i : A) cin >> i.x >> i.y;

    sort(all(A));
    vector<bool> done(n);
    vector<pair<int, int>> ans;
    
    int cx = -1e9;
    for(int i = 0; i < n; ){

        cx = max(cx + w, A[i].x + 1);

        vector<int> tmp;
        int ni = i;
        while(ni < n && A[ni].x <= cx){
            tmp.push_back(A[ni].y);
            ni++;
        }
        sort(all(tmp));

        int cy = tmp[0];
        ans.push_back(mp(cx, cy));
        for(int j = 1; j < (int)tmp.size(); j++){
            int ny = tmp[j];
            if (ny <= cy && cy <= ny + l) continue;

            cy = max(ny, cy + l + 1);
            ans.push_back(mp(cx, cy));
        }

        i = ni;
    }

    cout << (int)ans.size() << '\n';
    for(auto[a,b]: ans) cout << a << ' ' << b << '\n';

    

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