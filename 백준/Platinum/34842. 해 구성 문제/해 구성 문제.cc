#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    int n;
    cin >> n;

    vector<int> ans(n);
    if (n & 1) n--;

    int r = n % 8;

    int cur = 1;
    if (r == 2){
        ans[0] = 2;
        ans[1] = -1;
        cur = 3;
    }
    else if (r == 4){
        ans[0] = -3;
        ans[1] = 2;
        ans[2] = 1;
        ans[3] = -1;
        cur = 4;
    }
    else if (r == 6){
        ans[0] = 3;
        ans[1] = -3;
        ans[2] = 1;
        ans[3] = 4;
        ans[4] = -2;
        ans[5] = -1;
        cur = 5;
    }

    int p = 0;
    for(int i = r;i < n; i += 2){
        if (p == 0){
            ans[i] = cur;
            ans[i+1] = -cur;
        }
        else if ( p == 1){
            ans[i] = -cur;
            ans[i+1] = cur;
        }
        else if(p == 2){
            ans[i] = -cur;
            ans[i+1] = cur;
        }
        else if (p == 3){
            ans[i] = cur;
            ans[i+1] = -cur;
        }
        p = (p+1) % 4;
        cur++;
    }

    int res = 0;
    for(int i =0 ;i < n ;i++){
        res += (i+1)*ans[i];
    }
    cout << "Yes\n";
    for(auto f: ans) cout <<f << ' ';
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