#include <bits/stdc++.h>

using namespace std;

int grid[101][101];

vector<pair<int, int>> res[13];

int main(){

    ios::sync_with_stdio(false);

    cin.tie(0);

    int k;

    cin >>k;

    int ans = log2(k);

    if (pow(2, ans) < k) ans++;

    for(int i = 0; i < 100; i++){

        grid[i][99] = (1 << ans) - 1;

        grid[99][i] = (1 << ans) - 1;

    }

    for(int i = 1; i <= ans; i++){

        if (i <= 6){

            for(int j = 0; j < 64; j++){

                if (j & (1 << (i-1))){

                    for(int k = 0; k < 100; k++){

                        grid[k][j] = grid[k][j] | (1 << (i-1));

                    }

                }

            }

        }

        else{

            for(int j = 0;j < 64; j++){

                if (j & (1 << (i-7))){

                    for(int k = 0; k < 100; k++){

                        grid[j][k] |= (1 << (i-1));

                    }

                }

            }

        }

    }

    for(int i = 0; i < 100; i++){

        for(int j = 0;j < 100; j++){

            if (grid[i][j] >= k-1) grid[i][j] = (1 << ans) - 1;

        }

    }

    for(int i = 0; i < 100; i++){

        for(int j = 0; j < 100; j++){

            for(int k = 0; k < ans; k++){

                if (grid[i][j] & (1 << k)){

                    res[k].push_back({i+1, j+1});

                }

            }

            //cout << grid[i][j] <<' ';

        }

        //cout << '\n';

    }

    cout << ans <<'\n';

    for(int i = 0; i <ans; i++){

        cout << res[i].size() << ' ';

        for(auto k :res[i]) cout << k.first <<' ' <<k.second << ' ';

        cout <<'\n';

    }

    return 0;

}

