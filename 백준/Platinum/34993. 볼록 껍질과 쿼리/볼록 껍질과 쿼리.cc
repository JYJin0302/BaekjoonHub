#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<pair<int, int>> rec[1010];

pair<int, int> ans[1010];

void solve(){

    int n;
    cin >> n;

    if (n & 1){
        for(int i = 3; i <= n; i += 2){
            cout << "? 3 " << i-2 << ' ' << i-1 << ' ' << i << endl;
            int m;
            cin >> m;
            for(int j =0 ; j< 3; j++){
                int a, b;
                cin >> a>> b;
                rec[i].push_back(mp(a, b));
            }
        }

        for(int i = 3; i < n; i+= 2){
            pair<int, int> res;
            for(auto f : rec[i]){
                for(auto s : rec[i+2]){
                    if (f == s) res = f;
                }
            }
            ans[i] = res;
        }
        for(int i = 4; i < n-2; i += 2){
            pair<int, int> p1= ans[i-1];
            pair<int, int> p2 = ans[i+1];
            for(auto f :rec[i+1]){
                if (f == p1 || f == p2){}
                else ans[i] = f;
            }
        }

        cout << "? 3 " << 1 << ' ' << 5 << ' '<< n << endl;
        vector<pair<int, int>> tmp;
        int m;
        cin >> m;
        while(m--){
            int a ,b;
            cin >> a>> b;
            tmp.push_back(mp(a, b));
        }

        for(auto f : rec[3]){
            for(auto s : tmp){
                if (f == s) ans[1] = f;
            }
        }

        for(auto f : rec[n]){
            for(auto s: tmp){
                if (f == s) ans[n] = f;
            }
        }

        for(auto f : rec[3]){
            if (f == ans[1] || f == ans[3]) {}
            else ans[2] = f;
        }
        for(auto f: rec[n]){
            if (f == ans[n-2] || f == ans[n]){}
            else ans[n-1] = f;
        }

        cout << "! ";
        for(int i =1; i <= n; i++) cout << ans[i].x << ' ' << ans[i].y << ' ';
        cout << endl;
    }
    else{
        for(int i = 3; i <= n; i += 2){
            cout << "? 3 " << i-2 << ' ' << i-1 << ' ' << i << endl;
            int m;
            cin >> m;
            for(int j =0 ; j< 3; j++){
                int a, b;
                cin >> a>> b;
                rec[i].push_back(mp(a, b));
            }
        }
        cout << "? 3 " << 1 << ' ' << n-1 << ' ' << n << endl;
        int m;
        cin >> m;
        for(int j =0 ; j< 3; j++){
            int a, b;
            cin >> a>> b;
            rec[n].push_back(mp(a, b));
        }

        for(int i = 1; i <= n; i+= 2){
            int p1 = i, p2 = i + 2;
            if (i == 1) p1= n;
            if (i == n - 1) p2 = n;

            for(auto f : rec[p1]){
                for(auto s : rec[p2]){
                    if (f == s) ans[i] = f;
                }
            }
        }

        for(int i = 2; i < n; i += 2){
            for(auto f :rec[i+1]){
                if (f == ans[i-1] || f == ans[i+1]){}
                else ans[i] = f;
            }
        }

        for(auto f: rec[n]){
            if (f == ans[1] || f == ans[n-1]) {}
            else ans[n] = f;
        }

        cout << "! ";
        for(int i =1; i <= n; i++){
            cout << ans[i].x << ' ' << ans[i].y << ' ';
        }
        cout << endl;

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