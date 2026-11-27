#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[33][101010];

void solve(){

    int n;
    cin >>n;

    string s;
    cin >>s;


    int k;
    cin >>k;

    vector<ll> cost(26);
    for(int i = 0; i < k; i++){
        char c;
        cin >> c;
        ll v;
        cin >> v;
        cost[c-'A'] = max(cost[c-'A'], v);
    }



    for(int i = 0; i < n; i++){

        if (s[i] == '?'){
            for(int j = 0; j < 26; j++){
                dp[j][i] = cost[j];
                dp[26][i] = max(dp[26][i], cost[j]);
            }
        }
        else{
            int tv = s[i] -'A';
            for(int j = 0; j <26; j++){
                if (j == tv) dp[j][i] = cost[j];
                else dp[j][i] = -1;
            }
            dp[26][i] = cost[tv];
        };
    }
    if (n == 1) {
            cout << dp[26][0];
            return;
    }

    int p = 2;
    while(n % p != 0) p++;
    int r = n/p;
    int dist = n/p;

    while(r && dist){
        //cout <<"Curr:"<< r << ' ' << dist <<'\n';
        for(int i = 0; i < r; i++){
            vector<ll> tmp(33);
            for(int k =0; k <= 26;k ++){
                bool ok = 1;
                ll tval = 0;
                for(int j = i; j < i + dist*p; j += dist){
                    tval += dp[k][j];
                    if (dp[k][j] < 0) ok = 0;
                }
                if (!ok) tval = -1;
                else{
                    if (k != 26) {
                        tval += cost[k]*n/dist;
                        //cout << "ADd;"  << cost[k]*n/dist << " => " << tval << '\n';

                    }
                }

                if (k != 26) tmp[k] = tval;
                tmp[26] = max(tmp[26], tval);
            }

            for(int k = 0; k <= 26; k++){
                dp[k][i] = tmp[k];
            }
        }


        r /= p;
        dist /= p;
    }

    cout << dp[26][0];

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
