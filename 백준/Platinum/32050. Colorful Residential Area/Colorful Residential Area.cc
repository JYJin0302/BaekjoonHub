#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int ans[55][55];

vector<int> idxLst[55];

void solve(int n){
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;

    if (n == 1){
        cout << "Yes\n";
        cout << A[0] << '\n';
        return;
    }

    int m = 0;
    while(m < n && A[m] != A[n-1]) m++;
    if (m == n-1){
        cout << "No\n";
        return;
    }
    
    for(int i = 0; i <= n; i++) idxLst[i].clear();
    
    for(int j =0 ; j <= m; j++) idxLst[A[j]].push_back(j);
    vector<bool> conn(n);

    memset(ans, 0, sizeof ans);
    vector<pair<int, int>> edg;
    vector<int> go(n);
    
    int pre = -1;
    for(int j = n-1; j > m; j--){
        int cur = A[j];

        if(idxLst[cur].empty()){
            edg.push_back(mp(pre, j));
        }
        else{
            for(auto f : idxLst[cur]){
                edg.push_back(mp(f, j));
                go[f] = j;
                conn[f] = 1;
            }
            pre = idxLst[cur].back();
        }

         for(auto[a,b] : edg) {
            ans[b][a] = cur;
            ans[n-1-a][b] = cur;
            ans[n-1-b][n-1-a] = cur;
            ans[a][n-1-b] = cur;
        }
        edg.clear();
    }
    
    if (!conn[0]){
        cout << "No\n";
        return;
    }
    for(int i =0 ; i <= m; i++){
        if (!conn[i]){

            int a = i, b = go[0];
            int cur = A[i];
            //cout << "ADd: " << a << ' ' << b << ' '<< cur << '\n';
            ans[b][a] = cur;
            ans[n-1-a][b] = cur;
            ans[n-1-b][n-1-a] = cur;
            ans[a][n-1-b] = cur;
        }
    }

    cout << "Yes\n";
    for(int i =0 ;i < n ;i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while(t) {
        solve(t);
       // cout << endl;
        cin >> t;
    }

    return 0;
}