#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

char G[2020][2020];
bool done[2020][2020];

void solve(){
    
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j<=m; j++){
            cin >> G[i][j];
        }
    }

    priority_queue<tuple<double, int, int>> pq;
    pq.push({0, 1, 1});
    pq.push({0, 2, 1});

    const double m2 = acos(-1) * 5 / 2;
    //cout << m2 << '\n';


    cout << setprecision(15);
    while(!pq.empty()){
        auto f = pq.top();
        pq.pop();

        auto x = get<1>(f), y = get<2>(f);
        auto d = -get<0>(f);
        if(done[x][y]) continue;

       // cout << x << ' ' << y << " | " << d << '\n';
        done[x][y] = 1;
        if(x == 2*n+1 && y == m){
            cout << d + 10<< '\n';
            return;
        }
        if(x == n*2 && y == m+1){
            cout << d +10<< '\n';
            return;
        }

        if (x & 1){
            // down
            if (x != n*2+1){
                char c = G[x/2+1][y];
                if(!done[x+1][y+1]){
                    if (c == 'O'){
                        pq.push({-(d + m2), x+1, y+1});
                    }
                    else{
                        pq.push({-(d+10), x+1, y+1});
                    }
                }
            }

            // right
            if (y != m && !done[x][y+1]){
                pq.push({-(d+10), x, y+1});
            }
        }   
        else{
            //down
            if (x != n*2 && !done[x+2][y]){
                pq.push({-(d+10),x+2, y});
            }

            // right
            if (y != m + 1){
                char c= G[x/2][y];
                if(!done[x+1][y]){
                    if (c == 'O') pq.push({-(d+m2), x+1, y});
                    else pq.push({-(d+10), x+1, y});
                }
            }
        }
    }




}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }   
    return 0;
}

