#include <bits/stdc++.h>
using namespace std;


int main(){
    
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    int k; 
    cin >> k;
    
    for (int i = 0; i < n; i++){
        
        // 최댓값과 위치 찾기
        int mv = A[i], mi = i;
        for (int j = i + 1; j < min(n, i + k + 1); j++){
            if (A[j] > mv) {
                mv = A[j], mi = j;
            }
        }
        
        while(mi != i){
            swap(A[mi], A[mi-1]);
            mi--;
            k--;
        }
        
    }
    
    for (int i : A) cout << i << ' ';
}