#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
using ld= long double;

char G[10][30];
void solve(){
    
    int n = 7, m = 24;
    for(int i = 0; i < n ;i++){
        for(int j = 0; j < m; j++){
            cin >> G[i][j];
        }
    }

    int d, h;
    cin >> d >> h;

    ld ans = 0;
    vector<int> ord(7);
    for(int i = d; i <= 7; i++){
        ord = vector<int>(7);
        for(int j = 0; j < d; j++) ord[6-j] = 1;

        do{
            vector<int> cnt(24);
            for(int j = 0; j < 24; j++){
                int cc = 0;
                for(int f = 0; f < 7; f++){
                    if (ord[f]){
                        if (G[f][j] == '.') cc++;
                    }
                }
                cnt[j] = cc;
            }
            sort(cnt.rbegin(), cnt.rend());

            int tot = 0, cur = 0;
            for(int j = 0; j < 24; j++){
                tot += cnt[j];
                cur++;
                if (cur >= h){
                    ld tval = 1.0 * tot / (i * cur);
                    ans = max(ans, tval);
                }
            }

        }while(next_permutation(ord.begin(), ord.end()));

    }
    cout << fixed << setprecision(10);
    cout << ans;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}