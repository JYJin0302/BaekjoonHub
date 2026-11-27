#include <bits/stdc++.h>
using namespace std;

bool isP[3001];
vector<int> P;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 2; i <= 3000; i++){
        if (isP[i]) continue;
        P.push_back(i);
        for (int j = i*2; j <= 3000; j+=i) isP[j] = 1;
    }
    
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        
        for (auto k : P) {
            while(x% k == 0) {
                cout << k << ' ';
                x /= k;
            }
        }
        if (x != 1) cout << x;
        cout << '\n';
    }
}