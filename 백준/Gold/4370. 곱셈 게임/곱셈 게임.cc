#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

    ll n;
    while(cin >> n){
        
        bool p = 1;
        while(n != 1){
            if (p){
                n = (n+8)/9;
            }
            else{
                n = (n+1)/2;
            }
            p ^= 1;
        }
        if (!p) cout << "Baekjoon wins.\n";
        else cout << "Donghyuk wins.\n";
    }
}