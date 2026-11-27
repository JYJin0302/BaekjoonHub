#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    
    vector<int> cnt(s1 + s2 + s3 + 1);
    
    for (int i = 1; i <= s1; i++){
        for (int j = 1; j <= s2; j++){
            for (int k = 1; k <= s3; k++){
                cnt[i + j + k]++;
            }
        }
    }
    
    int ans = 0, ccnt = -1;
    for(int i = 1; i <= s1 + s2 + s3; i++){
        if (cnt[i] > ccnt){
            ccnt = cnt[i];
            ans = i;
        }
    }
    
    cout << ans;
}