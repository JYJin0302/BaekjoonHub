#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

char G[10];
vector<array<int, 3>> lst;


void solve(){
    for(int i =0 ; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> G[i*3+j];
        }
    }

    char player;
    cin >> player;

    for(int i = 0; i < 3; i++){
        for(int j =0;j < 3; j++){
            // try set this cell
            if (G[i*3+j] != '-') continue;
            G[i*3+j] = player;
            bool ok = 0;
            for(auto[a,b,c] : lst){
                if(G[a] == G[b] && G[a] == G[c] && G[a]== player){
                    ok= 1;
                    break;
                }
            }

            if (ok){
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        cout << G[i*3+j];   
                    }
                    cout << '\n';
                }
                return;
            }
            G[i*3+j] = '-';

        }
    }
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    lst.push_back({0, 1, 2});
    lst.push_back({3, 4, 5});
    lst.push_back({6, 7, 8});
    lst.push_back({0, 3, 6});
    lst.push_back({1, 4, 7});
    lst.push_back({2, 5, 8});
    lst.push_back({0, 4, 8});
    lst.push_back({2, 4, 6});
    
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ":\n";
        solve();
    }
    return 0;
}