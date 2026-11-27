#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define rep(i,a,b) for (int i=a;i<(b);++i)

typedef long long ll;

vector<int> A[1010];

void solve(){
    
    int n;
    cin >> n;

    for(int i =0 ; i < n; i++){
        for(int j =0; j < 3; j++){
            int x;
            cin >> x;
            A[i].push_back(x);
        }

        sort(all(A[i]));
    }


    vector<int> res = A[0];
    for(int j = 0; j < n; j++){
        for(int k =0 ; k < 3;k++){
            res[k] = min(res[k], A[j][k]);
        }
    }

    cout << res[0] * res[1] * res[2] << '\n';

}


int main(){ 
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}