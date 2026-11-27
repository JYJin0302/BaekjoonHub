#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define x first
#define y second


string ans[202020];
void solve(){
    
    int n;
    cin >> n;
    vector<string> A(n);
    for(auto& i : A) cin >> i;

    string t;
    cin >> t;

    for(auto f : A){
        int cur = 0;
        int ix = 0;
        for(auto c : f){
            if (c == t[cur]){
                cur++;
                if (cur == int(t.size())) break;
            }
            else{
                ans[cur] += c;
            }
        }

        if (cur == int(t.size())){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    for(int i = 0; i < int(t.size()); i++){
        cout << ans[i];
        if (i != int(t.size()) - 1) cout << t[i];
    }
    cout << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}