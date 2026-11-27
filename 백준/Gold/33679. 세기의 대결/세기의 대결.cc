#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){

    int n;
    cin >> n;

    vector<int> A(n), B(n);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;

    int sa = 0, sb = 0;
    for(int i = 0; i < n; i++){
        
        vector<int> tmp;
        for(int j = 0 ;j < n; j++){
            int val = A[(i+j)% n];
            int iter = lower_bound(all(tmp), val)- tmp.begin();
            if (iter == tmp.size()) tmp.push_back(val);
            else tmp[iter] = val;
        }
        sa = max(sa, (int)tmp.size());

        tmp.clear();
        
        for(int j = 0 ;j < n; j++){
            int val = B[(i+j)% n];
            int iter = lower_bound(all(tmp), val)- tmp.begin();
            if (iter == tmp.size()) tmp.push_back(val);
            else tmp[iter] = val;
        }
        sb = max(sb, (int)tmp.size());
    }

    if (sa > sb) cout << "YJ Win!\n";
    else if(sa < sb) cout << "HG Win!\n";
    else cout << "Both Win!\n";
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}