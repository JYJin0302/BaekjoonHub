#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n;
array<int, 2> S[101];

void solve(){
    
    cin >> n;

    for(int i =1 ; i <= n; i++){
        S[i][0] = n+1-i;
        S[i][1] = n+1-i;
    }


    vector<array<int, 3>> ans;

    int cur = n;
    while(cur){
        
        //cout << "cur: " << cur << endl;
        if(S[cur][0] == cur && S[cur][1] == cur) {
            cur--;
            continue;
        }

        int ix = 0;
        for(int i = cur - 1; i >= 1; i--){
            if (S[i][0] == cur || S[i][1] == cur){
                ix = i;
                break;
            }
        }

        int j = 0;
        if (S[ix][j] != cur) j++;

        while(ix < cur){
            int nj = 0;
            if(S[ix+1][0] > S[ix+1][1]) nj = 1;
            ans.push_back({ix, S[ix][j], S[ix+1][nj]});
            swap(S[ix][j], S[ix+1][nj]);
            ix++;
            j = nj;
        }
        // for(int i = 1; i <= n; i++) cout << S[i][0] << ' ';
        // cout << '\n';
        
        // for(int i = 1; i <= n; i++) cout << S[i][1] << ' ';
        // cout << endl;
    }

    int oper = (int)ans.size();
    cout << oper << '\n';
    for(auto f : ans) cout << f[0] << ' ' << f[1] << ' ' << f[2] << '\n';

    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}