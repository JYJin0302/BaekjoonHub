#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<vector<int>> A(26);
    for (int i = 0; i < 52; i++){
        A[s[i] - 'A'].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < 25; i ++){
        for (int j = i+1; j < 26; j++){
            if (A[i][0] > A[j][0] && A[i][0] < A[j][1] && A[i][1] > A[j][1]){
                ans++;
            }
            else if (A[i][0] < A[j][0] && A[i][1] > A[j][0] && A[i][1] < A[j][1]){
                ans++;
            }
        }
    }
    cout << ans;
}