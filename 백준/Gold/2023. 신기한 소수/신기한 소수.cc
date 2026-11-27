#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    for (int i = 2; i*i <= x; i++){
        if (x % i == 0) return 0;
    }
    return 1;
}

vector<int> v, tmp;


void solve(int n){
    
    if (n == 1) {
        v = {2, 3, 5, 7};
        return;
    }
    
    solve(n-1);
    
    for(int i : v){
        for (int x = 1; x <= 9; x += 2){
            if (isPrime(i*10 + x)) tmp.push_back(i*10 + x);
        }
    }
    
    swap(v, tmp);
    tmp.clear();
}


int main(){
    int n;
    cin >> n;
    
    solve(n);
    
    for(int i : v) cout << i << '\n';
}