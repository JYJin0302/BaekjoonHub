#include <bits/stdc++.h>
using namespace std;

string S, s;
vector<int> A;

void solve(int idx, int d){
    int n = (s.size() - idx + d - 1) / d;
    
    if (n <= 2){
        if (n == 0) return;
        S += s[idx];
        A.push_back(n);
        return;
    }
    
    // 홀수 개 테스트
    bool ok = (n%2==1);
    for (int i = idx + 2*d; i < s.size(); i+=2*d){
        if (s[i] != s[i-2*d]) ok = 0;
    }
    
    if (ok){
        S += s[idx];
        A.push_back(1);
        
        solve(idx+d, d*2);
        return;
    }
    
    int tidx = idx + d;
    while(tidx < s.size() && s[tidx] == s[tidx-d]) tidx += d;
    
    int cnt = (tidx - idx) / d;
    S += s[idx];
    A.push_back(cnt);
    
    solve(tidx, d*(cnt+1));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s;
    solve(0, 1);
    
    cout << S << '\n';
    for(auto k : A) cout << k << ' ';
    
}