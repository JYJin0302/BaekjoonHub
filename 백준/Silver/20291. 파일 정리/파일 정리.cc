#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    vector<string> A;
    map<string, int> cnt;
    
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        
        for(int k = 0; k < s.size(); k++){
            if (s[k] == '.') {
                string tt = s.substr(k + 1, s.size());
                
                if (cnt[tt] == 0) {
                    cnt[tt]++;
                    A.push_back(tt);
                }
                else cnt[tt]++;
                break;
            }
        }
    }
    sort(A.begin(), A.end());
    for(auto i : A) {
        cout << i << ' ' << cnt[i]<<'\n';
    }
    
}