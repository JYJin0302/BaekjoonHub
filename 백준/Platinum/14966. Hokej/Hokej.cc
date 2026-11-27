#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int ans[6][505050];

void solve(){
    
    ll m, n;
    cin >> m >> n;

    vector<array<ll, 3>> A;
    for(int i =0 ; i < n ;i++){
        ll a, b;
        cin >> a>> b;
        A.push_back({a, b, i});
    }
    sort(all(A));
    reverse(all(A));

    int ix = 0, ir = 0;
    ll tot = 0;
    for(auto f : A){
        int d = f[1];
        int idx = f[2] + 1;
        for(int j = 0; j < d && ix < 6; j++){
            ans[ix][ir] = idx;
            tot += f[0];
            ir++;
            if (ir == m){
                ir = 0;
                ix++;
            }
        }
        if (ix == 6) break;
    }


    vector<array<int, 3>> rec;

    for(int j = 1;j < m; j++){
        set<int> out, in;
        for(int i =0  ;i < 6; i++){
            if (ans[i][j] != ans[i][j-1]){
                out.insert(ans[i][j-1]);
                in.insert(ans[i][j]);
            }
        }

        
        auto iter = in.begin();
        while(iter != in.end()){
            int val = *iter;
            if (out.find(val) != out.end()){
                out.erase(out.find(val));
                iter = in.erase(iter);
            } 
            else iter++;
        }

        while(!in.empty()){
            auto f= *in.begin();
            in.erase(in.begin());
            auto v = *out.begin();
            out.erase(out.begin());
            rec.push_back({j, v, f});
        }
    }

    cout << tot << '\n';
    for(int i =0 ; i < 6; i++){
        cout << ans[i][0] << ' ';
    }
    cout << '\n';
    cout << (int)rec.size() << '\n';
    for(auto f : rec) cout << f[0] << ' '<< f[1] << ' ' << f[2] << '\n';



}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
