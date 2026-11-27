#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b){
    if (a == b) return a;
    
    if (a > b) swap(a, b);
    
    while(b > a) b /= 2;
    return solve(a, b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        
        cout << solve(a, b) * 10 << '\n';
    }
}