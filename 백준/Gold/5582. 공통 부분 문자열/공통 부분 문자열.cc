#include <bits/stdc++.h>
using namespace std;

int grid[4001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    
    int ans = 0;
    for (int i = 1; i <= s1.size(); i++){
        for (int j = s2.size(); j >= 1; j--){
            if (s1[i-1] == s2[j-1]) grid[j] = grid[j-1] + 1;
            else grid[j] = 0;
            ans = max(ans, grid[j]);
        }
    }
    
    
    cout << ans;
}