#include <bits/stdc++.h>
using namespace std;

int from[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> cnt(n+1);
    
    int sn = 1;
    for (int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        
        for (int j = 0; j < a; j++) from[sn + j] = i;
        sn += a;
        
        cnt[i] = a - b;
        while (b--){
            int x, y;
            cin >> x >> y;
        }
    }
    
    int q;
    cin >> q;
    while(q--){
        
        int t;
        cin >> t;
        
        int a, b;
        if(t == 1){
            cin >> a;
            cout << cnt[a] << '\n';
        }
        else if (t == 2){
            cin >> a >> b;
            int x = from[a];
            cnt[x]++;
        }
        else{
            cin >> a >> b;
            int x= from[a];
            cnt[x]--;
        }
    }
}