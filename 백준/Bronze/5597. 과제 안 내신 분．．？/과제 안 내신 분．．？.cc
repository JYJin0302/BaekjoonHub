#include<iostream>
using namespace std;
int a[31];
int main(){
    
    for(int i = 0; i < 28; i++){
        int x;
        cin >> x;
        a[x]++;
    }
    
    for (int i = 1; i <= 30; i++){
        if (a[i] == 0) cout << i << '\n';
    }
}