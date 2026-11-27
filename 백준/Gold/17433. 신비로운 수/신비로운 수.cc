#include <bits/stdc++.h>
using namespace std;
#define INF 2100000000


int t, n;
int mod(int x, int y){
    int temp = x % y;
    if (temp < 0) temp += y;
    return temp;
}


int main(){
    
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> base(n);
        for(auto& i : base) cin >> i;
        
        sort(base.begin(), base.end());
        int mindiff = INF;
        for (int i = 1; i < n; i++){
            if (base[i] != base[i-1]) mindiff = min(mindiff, base[i] - base[i-1]);
        }
        
        if (mindiff == INF) {cout << "INFINITY\n"; continue;}
        
        vector<int> temp;
        for (int i = 1; i*i <= mindiff; i++){
            if (mindiff % i == 0) {
                if (i * i != mindiff) temp.push_back(i);
                temp.push_back(mindiff / i);
            }
        }
        sort(temp.rbegin(), temp.rend());
        
        bool ok = true;
        for (int i : temp){
            int b = mod(base[0], i);
            for (int k : base) if (mod(k, i) != b) {
                ok = false;
                break;
            }
            if (ok) {cout << i << '\n'; break;}
        }
        
    }
    
    
}