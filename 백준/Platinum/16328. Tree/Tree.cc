
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

int dist[101][101];

void solve(){

    int n, m;
    cin >> n >>m;

    for(int i =1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dist[i][j] = 105;
        }
        dist[i][i] = 0;
    }

    vector<bool> bl(n+1);
    for(int i = 0; i < n; i++){
        int x;
        cin >>x;
        bl[i+1] = x;
    }

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a>> b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    if (m == 1){
        cout << 0;
        return;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    vector<int> A;
    for(int i = 1; i <= n; i++){
        if (bl[i]) A.push_back(i);
    }

    int sz = A.size();

    int ans = n+10;
    for(int i = 0; i < sz; i++){
        for(int j = i+1; j <sz; j++){

            // try A[i], A[j];

            int u = A[i], v = A[j];
            int cnt = 0;
            for(int k = 0; k < sz; k++){
                int f = A[k];
                if (dist[u][f] <= dist[u][v] && dist[v][f] <= dist[u][v]){
                    cnt++;
                }
            }
            if (cnt >= m){
                ans = min(ans, dist[u][v]);
            }


        }
    }
    cout <<ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    //cin>>tc;
    while(tc--){
        solve();
    }
}
