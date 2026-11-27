#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    map<string, int> cnt;
    while(n--){
        string s;
        cin >> s;
        cnt[s]++;
    }
    
    int ans = 0;
    while(m--){
        string s;
        cin >> s;
        ans += cnt[s];
    }
    
    cout << ans;
}