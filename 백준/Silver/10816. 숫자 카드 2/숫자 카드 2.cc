#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, a;
    cin >> n;
    
    map<int, int> mp;
    for (int i = 0; i < n; i++){
        cin >> a;
        mp[a]++;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> a;
        cout << mp[a] << ' ';
    }
}