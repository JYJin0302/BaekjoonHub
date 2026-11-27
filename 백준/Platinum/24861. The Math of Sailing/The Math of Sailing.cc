#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()



void solve(){
    
    array<int, 4> I;
    for(int i =0; i < 4; i ++) cin >> I[i];

    vector<int> ord(4);
    for(int i =0 ;i <4 ;i++) ord[i] = i;

    pair<double, array<int, 4>> ans;
    ans.x = -1;
    ans.y = {0, 0, 0, 0};

    do{

        array<int, 4> res;
        for( int i =0 ;i < 4; i++){
            res[i] = I[ord[i]];
        }

        int v1 = (res[0] -1 ) * (res[3] - 1);
        int v2 = (res[1] - 1) * (res[2] - 1);

        double tans = 0;
        if (v1 == v2){
            tans = res[0] * res[3] + res[1] + res[2];
        }
        else if (v1 > v2){
            if (res[0] > res[3]) swap(res[0], res[3]);
            double tmp = 1.0 * v2 / (res[3] - 1) + 1;
            tans = tmp * res[3] + res[1] + res[2];
        }
        else{
            if (res[1] > res[2]) swap(res[1], res[2]);
            double tmp = 1.0 * v1 / (res[2] - 1) + 1;
            tans = tmp * res[2] + res[0] + res[3];
        }

        ans = max(ans, mp(tans, array<int, 4>({ord[0], ord[1], ord[2], ord[3]})));

    }
    while(next_permutation(all(ord)));

    //cout << ans.x << " | ";
    for(int i =0; i <4 ;i++) cout <<ans.y[i] + 1 << ' ';
    cout << '\n';

    array<double, 4> res;
    for(int i =0 ;i < 4; i++){
        res[i] = I[ans.y[i]];
    }

    int v1 = (res[0] - 1) * (res[3] - 1);
    int v2 = (res[1] - 1) * (res[2] - 1);

    if (v1 == v2){
        
    }
    else if (v1 > v2){
        if (res[0] > res[3]) res[3] = 1.0 * v2 / (res[0] - 1) + 1;
        else res[0] = 1.0 * v2 / (res[3] - 1) + 1;
    }
    else{
        if (res[1] > res[2]) res[2] = 1.0 * v1 / (res[1] - 1) + 1;
        else res[1] = 1.0 * v1 / (res[2] - 1) + 1;
    }

    cout << fixed << setprecision(10);
    for(int i =0 ;i <4 ;i ++) cout << res[i] << ' ';
    cout << '\n';

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

