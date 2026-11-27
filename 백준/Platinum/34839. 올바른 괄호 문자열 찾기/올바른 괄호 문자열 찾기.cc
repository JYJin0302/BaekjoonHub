#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    int t;
    cin >> t;

    if ( t == 1){
        
        int n;
        cin >> n;
        string s;
        cin >> s;

        int val = 0;
        pair<int, int> res = mp(0, 0);
        for(int i=0 ; i < n; i++){
            if (s[i] == '(') val++;
            else val--;
            res = min(res, mp(val, i + 1));
        }

        cout << (-res.x) * 1001 + res.y << '\n';

    }
    else{
        
        int n, w;
        cin >> n >> w;
        string s;
        cin >> s;

        pair<int, int> res = mp(-(w/1001), w % 1001);
         //   cout << res.x << ' ' << res.y << '\n';
        int val = 0;
        for(auto f : s) {
            if (f == '(') val++;
            else val--;
        }

        val *= -1;
        for(int i =0 ;i  < n;i++){
            if (s[i] == '(') val++;
            else val--;

            res = min(res, mp(val, i + n + 1));
        }

        cout << res.y + 1 << '\n';

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