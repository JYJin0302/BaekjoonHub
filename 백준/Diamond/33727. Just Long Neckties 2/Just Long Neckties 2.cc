#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int upd(int v, int x){

    for(int i = x-1; i >= 0; i--){
        if (v & (1 << i)){
            v ^= 1 << i;
            break;
        }
    }

    v ^= (1 << x - 1);
    return v;
}

bool cmp(int s1, int s2){
    int i1 = 0, i2 = 0;
    while(i1 < 21){
        while(i1 < 21 && (s1 & (1 << i1)) == 0) i1++;
        if (i1 == 21) return 1;
        i2 = max(i2, i1);
        while(i2 < 21 && (s2 & (1 << i2)) == 0) i2++;
        if (i2 == 21) return 0;
        i2++;
        i1++;
    }
    return 1;
}

string it2(int x){
    string res;
    for(int i =0  ; i< 21; i++){
        if(x & (1 << i)) res += '1';
        else res += '0';
    }
    return res;
}
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

void solve(){
    
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    // for(int i =0 ;i < n;i++){
    //     A[i] = rng() % 21 + 1;
    // }
    
    vector<int> dpO, dpS;

    dpO.push_back(1 << A[0] - 1);
    dpS.push_back(0);

    int mx = 0;
    for(int i = 1; i < n; i++){
        vector<int> tmp;

        for(auto f : dpS){
            tmp.push_back(upd(f, A[i]));
        }
        for(auto f : dpO){
            tmp.push_back(upd(f, A[i]));
        }
        swap(dpO, dpS);
        dpO.clear();

        sort(all(tmp));
        tmp.erase(unique(all(tmp)), tmp.end());
        
        for(auto f: tmp){
            bool ok = 1;
            for(auto k : tmp){
                if (f == k) continue;
                if (cmp(k, f)) {
                    ok = 0;
                    break;
                }
            }
            if (ok) dpO.push_back(f);
        }

        mx = max({mx, (int)dpO.size(),(int)dpS.size()});

        // cout << "O : ";
        // for(auto f: dpO){
        //     cout << it2(f) << ' ';
        // }
        // cout << '\n';
        // cout << "S : ";
        // for(auto f: dpS){
        //     cout << it2(f) << ' ';
        // }
        // cout << '\n';
        // cout << '\n' << '\n';
    }

    int ans = 21;
    for(auto f : dpS){
        ans = min(ans, __builtin_popcount(f));
    }
    for(auto f: dpO){
        ans = min(ans, __builtin_popcount(f));
    }
    cout << ans << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
   // cin >> t;
    while(t--) {
       // cout << "Go: " << endl;
        solve();
        //cout << endl;
    }

    return 0;
}