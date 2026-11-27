#include <bits/stdc++.h>
using namespace std;

const double PI = 3.141592;

double one(char c){
    
    if (c == 'T') return 1.5;
    if (c == 'S') return 2;
    if (c == 'C') return PI / 2;
    
}

double two(int x, char c){
    
    if (x == 0) return 0;
    
    double h = sqrt(3) / 2;
    if (c == 'S'){
        return 0.5 + sqrt((x - 0.5) * (x - 0.5) + (1 - h) * (1 - h));
    }
    
    if (c == 'C'){
        
        double dist = sqrt(x*x + (h - 0.5) * (h - 0.5));
        double a1, a2;
        
        a1 = acos(0.5 / dist);
        a2 = atan((h - 0.5) / x);
        
        return tan(a1) / 2 + (PI / 2 - a1 - a2) / 2;
        
    }
    
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << fixed << setprecision(10);
    
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    double ans = 0;
    
    // 왼쪽, 아래, 오른쪽
    ans = n - 1 + one(s[0]) + one(s[n-1]);
    
    int l = 0, r = n-1;
    
    while(l < n && s[l] == 'T') l++;
    while(r >= 0 && s[r] == 'T') r--;
    
    
    if (l == n) ans += n - 1;
    else{
        
        ans += two(l, s[l]);
        ans += two(n - 1 - r, s[r]);
        ans += r - l;
    }
    
    cout << ans;
}