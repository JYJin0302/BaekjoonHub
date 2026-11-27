#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[2030][2030], tmp[2030][2030];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll r, n, mod;
    cin >> r >> n >> mod;

    if (r == n){
        if(r == 1) cout <<1 %mod;
        else cout <<0;
        return 0;
    }
    if (mod == 1){
        cout << 0;
        return 0;
    }

    dp[1][0] = 1;
    vector<pair<int, int>> curr;
    curr.push_back({1, 0});
    for(int i = n-1; i > 0; i--){

        if(i == r){
            //cout << "TArget\n";
            for(auto& k : curr){
                int a, b;
                tie(a, b) = k;

                tmp[a-1][b+1] += dp[a][b] * a %mod;
                tmp[a-1][b+1] %= mod;
                if (b >0) {
                    tmp[a][b-1] += dp[a][b] * b % mod;
                    tmp[a][b-1] %= mod;
                }

                k = {a-1, b+1};
            }

            if(curr.back().second == 2){
                curr.push_back({curr.back().first+1, 0});
            }
            swap(dp, tmp);
            /*
            for(int j =0; j <= n; j++){
            for(int k = 0; k <= n; k++){
                cout <<dp[j][k] <<' ';
            }
            cout <<'\n';

        }*/

            continue;
        }

        //cout << "curr: \n";
        for(auto& k : curr){
            int a, b;
            tie(a, b) = k;
            //cout <<a <<' ' << b <<'\n';

            dp[a][b+1] += dp[a][b] * a % mod;
            dp[a][b+1] %= mod;

            if (b > 0) {
                dp[a+1][b-1] += dp[a][b] * b % mod;
                dp[a+1][b-1] %= mod;
            }

            k = {a, b+1};
        }

        if(curr.back().second == 2){
            curr.push_back({curr.back().first+1, 0});
        }

        /*
        for(int j =0; j <= n; j++){
            for(int k = 0; k <= n; k++){
                cout <<dp[j][k] <<' ';
            }
            cout <<'\n';
        }
        */

    }


    ll ans = 0;
    for(auto i : curr){
        int a, b;
        tie(a, b) = i;
        ans = (ans +dp[a][b])% mod;

    }
    cout <<ans;

}
