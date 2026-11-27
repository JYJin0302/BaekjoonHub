#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    map<int ,int> pcnt;
    for (int j = 1; j <= n; j++){
        int tn = j;
       for (int i = 2; i*i <= tn; i++){
           while(tn % i == 0){
               tn /= i;
                pcnt[i]++;
            }
        } 
    if (tn != 1) pcnt[tn]++;
    }
    
    int k = min(pcnt[2], pcnt[5]);
    pcnt[2] -= k, pcnt[5] -= k;
    
    int ans = 1;
    for (auto i = pcnt.begin(); i != pcnt.end(); i++){
        while (i->second != 0) {
            ans = ans * (i->first) % 10;
            i->second--;
        }
    }
    cout << ans;
}