#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int A[10][1010];

void solve(){
    
    int n, q;
    cin >> n>> q;


    while(q--){
        int t;
        cin >> t;
        if (t == 1){
            int a, b;
            cin >> a>> b;

            A[a][b]++;
            A[a-1][b]++;
            A[a+1][b]++;
            A[a][b-1]++;
            A[a][b+1]++;
        }   
        else{

            int a;
            cin >> a;
            int cur = A[a][1];
            int curi = 1;
            for(int j= 2; j <= n; j++){
                if (A[a][j] > cur){
                    cur = A[a][j];
                    curi = j;
                }
            }

            cout << curi << '\n';
        }
    }

    int curV = A[1][1];
    pair<int, int> ret = mp(1, 1);
    for(int i =1; i <= 4; i++){
        for(int j =1; j <= n; j++){
            if (A[i][j] > curV){
                curV = A[i][j];
                ret = mp(i, j);
            }
        }
    }
    cout << ret.x << ' ' << ret.y << '\n';

    

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