#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<string> A;
    map<string, int> cnt;
    
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        
        if (cnt[s] == 0) A.push_back(s);
        cnt[s]++;
    }
    
    string ans = "NONE";
    for (auto i : A) if (cnt[i] >= n/2 + 1) ans = i;
    
    cout << ans;
    
}