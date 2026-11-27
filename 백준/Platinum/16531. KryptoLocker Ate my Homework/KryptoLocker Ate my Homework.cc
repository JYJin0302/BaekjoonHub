#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

ll G[3030][3030];


void solve(){
    
    int n;
    cin >> n;

    int sn = (1 << n);
    vector<int> A(sn);
    for(auto& i : A) cin >> i;

    int mx = *max_element(all(A));
    int mn = *min_element(all(A));

    vector<int> ans;
    while((int)ans.size() < n){
        sort(all(A));
        // for(auto f: A) cout <<f << ' ';
        // cout << '\n';

        int val = A[1] - A[0];
        ans.push_back(val);

        map<int, int> cnt;
        vector<int> newA;
        for(auto f :A){
            if (cnt[f]) cnt[f]--;
            else{
                newA.push_back(f);
                cnt[f+val]++;
            }
        }
        swap(A, newA);
    }

    sort(all(ans));

    vector<vector<int>> rep;
    for(int i =0  ;i < (1 << n); i++){
        ll tot = 0;
        for(int j = 0;j < n; j++){
            if (i & (1 << j)){
                tot += ans[j];
            }
        }
        if (tot == mx){
            vector<int> tmp;
            for(int j =0 ;j < n; j++){
                if (i & (1 << j)) tmp.push_back(ans[j]);
                else tmp.push_back(-ans[j]);
            }
            sort(all(tmp));
            rep.push_back(tmp);
        }
    }

    sort(all(rep));
    rep.erase(unique(all(rep)), rep.end());

    for(auto f : rep){
        for(auto a : f) cout << a<< ' ';
        cout << '\n';
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

