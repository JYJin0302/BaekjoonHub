#include <bits/stdc++.h>
using namespace std;

int main(){
    int ans = 0, a;
    for (int i = 0; i < 5; i++){
        cin >> a;
        ans += a*a;
    }
    cout << ans%10;
}