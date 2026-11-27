#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()



void solve(){

    int n;
    cin >> n;

    if (n == 2){
        cout << "a2 > b2 ? a1\n";
        return;
    }

    vector<array<int, 6>> rec;


    for(int i = n; i >= 3; i--){
        for(int j = n; j >= 1; j--){

            // make A[i][j] max

            // move maximum to [i-1][j]

            for(int a = 1; a < i - 1; a++){
                for(int b = 1; b < j; b++){
                    rec.push_back({a, b+1, a+1, b+1, a, b});
                    rec.push_back({a, b, a+1, b+1, a, b});
                    rec.push_back({a+1, b, a+1, b+1, a, b});
                }
                for(int b = n - 1; b >= j; b--){
                    rec.push_back({a+1, b+1, a+1, b, a, b});
                    rec.push_back({a, b+1, a+1, b, a, b});
                    rec.push_back({a, b, a+1, b, a, b});
                }
            }

            if(j == 1){
                rec.push_back({i-1, j, i, j, i-2, j});
                rec.push_back({i-1, j+1, i, j, i-2, j});

                rec.push_back({i-2, j+1, i, j, i-1, j});

                rec.push_back({i-1, j+1, i, j+1, i-2, j});
                rec.push_back({i-2, j+1, i, j+1, i-2, j});
                rec.push_back({i-2, j  , i, j+1, i-2, j});

                rec.push_back({i-1, j  , i, j+1, i-1, j});
                rec.push_back({i  , j  , i, j+1, i-1, j});
            }
            else{

                int a = i-1;
                for(int b =1 ; b < j; b++){                    
                    rec.push_back({a, b+1, a+1, b+1, a, b});
                    rec.push_back({a, b, a+1, b+1, a, b});
                    rec.push_back({a+1, b, a+1, b+1, a, b});
                }

            }

        }
    }
    
    for(auto f: rec){
        cout << char('a' + f[1] - 1) << f[0] << " > " << char('a' + f[3] - 1) << f[2] << " ? " << char('a' + f[5] - 1) << f[4] << '\n';
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

