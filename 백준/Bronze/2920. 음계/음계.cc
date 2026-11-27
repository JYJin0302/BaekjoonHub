#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> A(8);
    for(auto& i : A)cin >> i;
    
    bool des = 0, asc = 0;
    for (int i = 1; i < 8; i++){
        if (A[i] > A[i-1]) asc = 1;
        else des = 1;
    }
    
    if (asc && des) cout << "mixed";
    else if (asc) cout << "ascending";
    else cout << "descending";
}