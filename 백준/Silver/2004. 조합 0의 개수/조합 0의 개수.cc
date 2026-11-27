#include <bits/stdc++.h>
using namespace std;

int twos(int x){
    int ans = 0;
    for (int i = 1; i<=30; i++){
        ans += x/(pow(2, i));
    }
    return ans;
}

int fives(int x){
    int ans = 0;
    for (int i = 1; i <= 13; i++){
        ans += x/(pow(5, i));
    }
    return ans;
}


int main(){
    int n, m;
    cin >>n >> m;
    
    int a = n, b = n-m, c = m;
    int tot2 = twos(a) - twos(b) - twos(c);
    int tot5 = fives(a) - fives(b) - fives(c);
    
    cout << max(0, min(tot2, tot5));
}