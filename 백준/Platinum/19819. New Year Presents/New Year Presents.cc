#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> A[101010];

int sz[101010];

vector<int> lst[101010];

int nxt[101010];
int find(int n){
    if (nxt[n] == n) return n;
    return nxt[n] = find(nxt[n]);
}
void solve(){
    
    int n, k;
    cin >> n >> k;

    int tot = 0;
    for(int i= 1; i <= n; i++){
        int d;
        cin >> d;
        sz[i] = d;
        tot += d;
        vector<int> tmp(d);
        for(auto& f : tmp) {
            cin >> f;
        }
        A[i] = tmp;
    }
    

    int l = tot / n;
    int r = l;
    if (tot % n) r++;

    // r 보다 큰 애들 -> l 보다 작은 애들
    
    for(int i = 1; i <= n; i++){
        if (sz[i] > r){
            for(auto f : A[i]){
                lst[f].push_back(i);
            }
        }
    }
    for(int j =1; j <= k; j++){
        if (lst[j].empty()) nxt[j] = j+1;
        else nxt[j] = j;
    }

    vector<int> nSz(n+1);
    for(int i =1 ; i <= n; i++){
        if (sz[i] > r) nSz[i] = r;
        else if (sz[i] < l) nSz[i] = l;
        else nSz[i] = sz[i];
    }

    int lcnt = 0;
    for(int i = 1;i <= n; i++){
        if (nSz[i] == l) lcnt++;
    }
    for(int i = 1; i <= n && lcnt > n - (tot % n); i++){
        if (nSz[i] == l) {
            nSz[i]++;
            lcnt--;
        }
    }

    // for(int i =1; i <= n;i++){
    //     cout << sz[i] << " | " << nSz[i] << '\n';
    // }


    vector<array<int, 3>> ans;
    for(int i = 1; i <= n; i++){
        if (sz[i] < nSz[i]){

            sort(all(A[i]));

            int sn = (int)A[i].size();
            int tar = 1;
            int ti = 0;
            while(tar <= k && sz[i] < nSz[i]){
                tar = find(tar);
                while(ti < sn && A[i][ti] < tar) ti++;

                if (ti < sn && tar == A[i][ti]) {
                    tar++;
                    ti++;
                    continue;
                }

                while(!lst[tar].empty()){
                    auto f =lst[tar].back(); lst[tar].pop_back();
                    if(sz[f] == r) continue;
                    sz[f]--;
                    sz[i]++;
                    ans.push_back({f, i, tar});
                    break;
                    //cout << "Ans add: " << f << ' '<< i << ' '<< tar << endl;
                }
                if (lst[tar].empty()) nxt[tar] = tar + 1;
                tar++;
            }

            assert(sz[i] == nSz[i]);
        }
    }


    cout << (int)ans.size() << '\n';
    for(auto f : ans) cout << f[0] << ' '<< f[1] << ' '<< f[2] << '\n';

    

    
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
