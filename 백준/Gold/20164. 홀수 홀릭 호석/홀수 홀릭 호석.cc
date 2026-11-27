#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

pair<int, int> solve(string s){
    int m = 0, M = 0;
    for(char c : s) m += (c - '0') % 2;
    M = m;
    
    if (s.size() == 1) return {m, M};
    
    if (s.size() == 2){
        int n = (s[0] - '0') + (s[1] - '0');
        pair<int, int> v = solve(to_string(n));
        m += v.x, M += v.y;
        return {m, M};
    }
    
    int tm = 1000, tM = 0;
    for(int i = 0; i < s.size(); i++){
        for (int j = i+1; j < s.size() - 1; j++){
            
            string s1, s2, s3;
            s1 = s.substr(0, i+1);
            s2 = s.substr(i+1, j - i);
            s3 = s.substr(j+1, s.size());
            
            int N = stoi(s1) + stoi(s2) + stoi(s3);
            pair<int, int> r = solve(to_string(N));
            
            tm = min(tm, r.x);
            tM = max(tM, r.y);
        }
    }
    return {m + tm, M + tM};
}

int main(){
    
    string s;
    cin >> s;
    pair<int, int> A = solve(s);
    
    cout << A.x << ' ' << A.y;
}