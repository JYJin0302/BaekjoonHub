#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >>s;

    sort(s.begin(), s.end());
    int n = s.size() / 2;

    if (n == 1){
        if (s[0] == s[1]) cout <<"NO";
        else {
            cout <<"YES\n" <<s;
        }
        return 0;
    }

    vector<int>cnt(26);
    for(auto i : s) cnt[i-'a']++;

    int mdx = max_element(cnt.begin(), cnt.end()) - cnt.begin();
    if (cnt[mdx] >= 2*n-1){
        cout <<"NO\n";
        return 0;
    }

    //cout <<mdx <<' ';
    if (cnt[mdx] <= n){
        cout << "YES\n" << s ;
        return 0;
    }

    int tcnt = 0;
    vector<int>idxList;
    for(int i = 0; i < 26; i++){
        if (i != mdx && cnt[i] > 0) {
                idxList.push_back(i);
                tcnt += cnt[i];
        }
    }

    if (idxList.size() > 1){
            //cout <<"WTF";
        string res(2*n, '!');
        for(int i = 0; i < n; i++){
            res[i] = ('a' + mdx);
        }
        cnt[mdx] -= n;
        res[n] = (idxList[0] +'a');
        res[2*n-1] = (idxList[1]+'a');
        cnt[idxList[0]]--;
        cnt[idxList[1]]--;

        int ix = n+1;
        for(int i = 0; i< 26; i++){
            while(cnt[i] >0){
                cnt[i]--;
                res[ix] = ('a' +i);
                ix++;
            }
        }

        cout <<"YES\n" <<res;
        return 0;
    }

    int nx = idxList[0];
    if(cnt[nx] > 2 || n == 2){

        string res(n*2, ('a' + mdx));
        cnt[nx] --;
        res[n] = ('a' +nx);

        int ix = n*2-1;
        while(cnt[nx] > 0){
            cnt[nx]--;
            res[ix] = ('a' + nx);
            ix--;
        }


        cout <<"YES\n"<<res ;
        return 0;
    }

    cout <<"NO";
}
