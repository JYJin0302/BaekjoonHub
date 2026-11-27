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
    while(n){
        vector<int> A(n);
        for(auto& i : A) cin >> i;

        int tot = 0;
        for(auto f : A) if (tot + f <= 300) tot += f;

        cout << tot << '\n';
        cin >> n;
    }
    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--) solve();

    return 0;
}