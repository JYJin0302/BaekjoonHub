#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;

void solve(){
    
    string s;
    cin >> s;

    int n = (int)s.size();

    int res = 0;
    int cnt = 0;
    for(int j = n-1; j >= 0; j--){
        if(s[j] == '1'){
            res = (res + cnt) % 3;
        }
        else{
            cnt = (cnt+1) % 3;
        }
    }

    if (res) cout << "Alice\n";
    else cout << "Bob\n";

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}