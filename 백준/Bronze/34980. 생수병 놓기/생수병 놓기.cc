#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){
    
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2){
        cout << "Good\n";
        return;
    }

    int cnt1 = 0;
    int cnt2 = 0;
    for(auto f : s1) if (f == 'w') cnt1++;
    for(auto f : s2) if (f == 'w') cnt2++;

    if (cnt1 == cnt2){
        cout << "Its fine\n";
    }
    else if (cnt1 > cnt2) cout << "Oryang\n";
    else cout << "Manners maketh man\n";
    
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