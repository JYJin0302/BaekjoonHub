#include <bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> A(9);
    for(auto& i : A) cin >> i;
    
    int tot = 0;
    for(auto i : A) tot += i;
    
    if (tot < 100) {
        cout << "none";
        return 0;
    }
    
    for (int i = 0; i < 9; i++){
        if (A[i] > 100 * (i / 2+ 1)){
            cout << "hacker";
            return 0;
        }
    }
    
    cout << "draw";
}