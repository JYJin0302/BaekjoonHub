#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second
 
void solve() {
    
    int n;
    cin >> n;
 
    map<string, int> lst;
    map<string, bool> pin;
    for(int i = 0 ;i < n ;i++){
        string s;
        cin >> s;
 
        lst[s] = i+1;
    }
    int k;
    cin >> k;
    while(k--){
        string s;
        cin >> s;
        pin[s] = 1;
    }
 
    vector<pair<pair<int, int>, string>> A;
    for(auto f : lst){
        string s = f.x;
        A.push_back(mp(mp(pin[s], f.y), s));
    }
    sort(all(A));
    reverse(all(A));
    
    for(auto f : A) cout << f.y << '\n';
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
 
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
