#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define rep(i,a,b) for (int i=a;i<(b);++i)

typedef long long ll;

void solve(){
    
    int a, b, c;
    cin >> a>> b >> c;

    if(a+b < c || b+c< a|| c+a<b){
        cout << "No\n";
        return;
    }

    int mx = max({a, b, c});

    if (mx == 0){
        cout << "Yes\n";
        string s = "aaa";
        for(int j = 0; j < 3; j++) cout << s<< '\n';
        return;
    }

    vector<string> ans(3);
    if (a == mx){
        ans[0] = string(mx, 'a');
        ans[1] = string(mx, 'b');
        ans[2] = string(mx, 'c');

        for(int i =0; i < mx - b; i++){
            ans[2][i] = 'a';
        }
        for(int i = 0; i < mx-c; i++){
            ans[2][mx-1-i] = 'b';
        }
    }
    else if (b == mx){
        ans[0] = string(mx, 'a');
        ans[1] = string(mx, 'c');
        ans[2] = string(mx, 'b');

        for(int i =0; i < mx - a; i++){
            ans[1][i] = 'a';
        }
        for(int i = 0; i < mx-c; i++){
            ans[1][mx-1-i] = 'b';
        }
    }
    else{
        ans[0] = string(mx, 'c');
        ans[1] = string(mx, 'a');
        ans[2] = string(mx, 'b');

        for(int i =0; i < mx - a; i++){
            ans[0][i] = 'a';
        }
        for(int i = 0; i < mx-b; i++){
            ans[0][mx-1-i] = 'b';
        }
    }

    cout << "Yes\n";
    for(auto f :ans) cout <<f << '\n';


}


int main(){ 
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}