#include <bits/stdc++.h>
using namespace std;

int main(){
    int sum = 0;
    vector<int> base(9);
    for (auto& i : base) {
        cin>>i;
        sum+= i;
    }
    int n1, n2;
    bool found = false;
    sort(base.begin(), base.end());
    int no = sum - 100;
    for (int i = 0; i < 9; i++){
        for (int j = i + 1; j < 9; j++){
            if (base[i] + base[j] == no){
                found = true;
                n1 = i;
                n2 = j;
                break;
            }
        }
        if (found) break;
    }
    
    for (int i = 0; i < 9; i++){
        if (i == n1 || i == n2) continue;
        cout << base[i] << '\n';
    }
    
}