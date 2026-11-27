#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


ll ans[1010];

int ask(int i1, int i2, int i3){
    cout << "? " << i1 << ' '<< i2 << ' ' << i3 << endl;
    int x = 0;
    cin >> x;
    // int mn = min({test[i1], test[i2], test[i3]});
    // int mx = max({test[i1], test[i2], test[i3]});
    // x = mn + mx;
    return x;
}


bool solveEq(vector<array<ll, 6>> A){
    int n = 6;
    assert((int)A.size() == n);

    vector<ll> val(6);
    for(int i = 0; i < 6; i++){
        val[i] = A[i][5];
    }

    vector<ll> res(5);
    ll tmp = val[0] + val[2] + val[5];
    if (tmp & 1) return 0;
    tmp >>= 1;
    res[0] = tmp - val[5];
    res[2] = tmp - val[2];
    res[4] = tmp - val[0];
    res[1] = val[4] - res[4];
    res[3] = val[3] - res[1];

    for(auto f: res){
        if(f < 0 || f > (ll)1e9) return 0;
    }
    
    for(int i = 0; i < 5; i++) ans[i] = res[i];
    return 1;
}


void goSolve5(){

    vector<array<int, 4>> data;

    for(int i =1; i <= 5; i++){
        for(int j = i+1; j <= 5; j++){
            for(int k = j+1; k <= 5; k++){
                int r = ask(i, j, k);
                data.push_back({i, j, k, r});
            }
        }
    }

    vector<int> ord(5);
    for(int i =0 ;i < 5; i++){
        ord[i] = i;
    }


    do{

        vector<array<ll, 3>> data2;
        vector<array<ll, 6>> data3;


        for(auto f: data){
            int maxO = -1;
            int minO = -1;

            for(int j =0 ;j < 3; j++){
                int o = ord[f[j]-1];
                if (maxO == -1 || maxO < o) maxO = o;
                if (minO == -1 || minO > o) minO = o;
            }

            array<ll, 3> tmp = {0, 0, 0};
            tmp[0] = minO;
            tmp[1] = maxO;
            tmp[2] = f[3];

            data2.push_back(tmp);
        }

        sort(all(data2));

        
        bool ok = 1;

        for(int i = 0;i < (int)data2.size(); i++){
            if(i && data2[i][0] == data2[i-1][0] && data2[i][1] == data2[i-1][1]){
                if (data2[i][2] != data2[i-1][2]) ok = 0;
            }
            else {
                array<ll,6> tmp = {0, 0, 0, 0, 0, 0};
                tmp[data2[i][0]] = 1;
                tmp[data2[i][1]] = 1;
                tmp[5] = data2[i][2];
                data3.push_back(tmp);
            }
        }

        if (!ok) continue;

        ok = solveEq(data3);
        if(!ok) continue;

        vector<ll> tmp(5);
        for(int i =0 ; i <5 ;i++){
            int o = ord[i];
            tmp[i] = ans[o];
        }
        for(int i = 0; i < 5; i++) ans[i+1] = tmp[i];
        return;
        // for(auto f :data3){
        //     for(int j =0 ; j < 6; j++){
        //         cout << f[j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';


    }while(next_permutation(all(ord)));



}   

void solve(){
    

    int n;
    cin >> n;

    goSolve5();

    vector<pair<int, int>> A;
    for(int i = 1; i <= 5; i++) A.push_back(mp(ans[i], i));

    sort(all(A));

    for(int i = 6; i <= n; i++){
        int v1 = ask(A[0].y, A[1].y, i);
        if(v1 == A[0].x + A[1].x){
            v1 = ask(A[3].y, A[4].y, i);
            ans[i] = v1 - A[4].x;
        }
        else if (v1 < A[0].x + A[1].x) ans[i] = v1 - A[1].x;
        else ans[i] = v1 - A[0].x;
    }

    cout << "! ";
    for(int i =1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;

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
