#include <bits/stdc++.h>
using namespace std;

const int INF = 1000001;
bool isPrime[INF];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    memset(isPrime, 1, INF);
    for (int i = 2; i < INF; i++){
        if (isPrime[i]) {
            for(int j = i*2; j < INF; j+=i) isPrime[j] = 0;
        }
    }
    
    int t;
    cin >> t;
    
    while(t--){
        
        int x, cnt = 0;
        cin >> x;
        
        for (int i = 2; i <= x/2; i++){
            if (isPrime[i] && isPrime[x - i]) cnt++;
        }
        
        cout << cnt << '\n';
    }
    
}