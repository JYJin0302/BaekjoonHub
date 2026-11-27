
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N;
int segM[550000], segm[550000];
int A[300000];

void init(int l, int r, int n){
    if (l == r) {

        if (l < N) segM[n] = segm[n] = A[l];
        else{
            segM[n] = -1;
            segm[n] = 1e9+10;
        }
        return;
    }

    int m = (l+r)>>1;
    init(l, m, n*2);
    init(m+1, r, n*2+1);

    segM[n] = max(segM[n*2], segM[n*2+1]);
    segm[n] = min(segm[n*2], segm[n*2+1]);
}

int getVal(int l, int r, int n, int sl, int sr, bool M){
    if (l > sr || r < sl){
        if (M) return -1;
        return 1e9 + 10;
    }
    if (l>= sl && r <=sr) {
        if(M) return segM[n];
        return segm[n];
    }

    int m = (l+r)>>1;

    int v1  = getVal(l, m, n*2, sl, sr, M);
    int v2 = getVal(m+1 ,r, n*2+1, sl, sr, M);

    if(M) return max(v1, v2);
    return min(v1,v2);
}



void solve(){

    cin >> N;

    int sn = 1;
    while(sn < N) sn*=2;

    for(int i =0 ; i < N; i++) cin >> A[i];

    init(0, sn-1, 1);

    set<string> ans;

    for(int i = 1; i < N-1; i++){
        // 1 1 1, -1 -1 -1
        if (getVal(0, sn-1, 1, 0, i-1, 0) < A[i] && A[i] < getVal(0, sn-1, 1, i+1, N-1, 1)){
            ans.insert("123");
        }
        if (getVal(0, sn-1, 1, 0, i-1, 1) > A[i] && A[i] > getVal(0, sn-1, 1, i+1, N-1, 0)){
            ans.insert("321");
        }
    }

    map<int, int> ck;

    for(int i = 0; i < N; i++){
        if (ck[A[i]] && A[i] < getVal(0, sn-1, 1, i+1, N-1, 1)) {
            ans.insert("112");
        }
        if (ck[A[i]] && A[i] > getVal(0, sn-1, 1, i+1, N-1, 0)) {
            ans.insert("221");
        }
        ck[A[i]]++;

        if(ck[A[i]] == 3) ans.insert("111");
    }
    ck.clear();

    for(int i = N-1; i >= 0; i--){
        if (ck[A[i]] && getVal(0, sn-1, 1, 0, i-1, 0) < A[i]) {
            ans.insert("122");
        }
        if (ck[A[i]] && getVal(0, sn-1, 1, 0, i-1, 1) > A[i]) {
            ans.insert("211");
        }
        ck[A[i]]++;
    }
    ck.clear();

    for(int i = 0; i < N; i++){
        if (ck[A[i]] && getVal(0, sn-1, 1, ck[A[i]]-1, i-1, 0) < A[i]){
            ans.insert("212");
        }
        if (ck[A[i]] && getVal(0, sn-1, 1, ck[A[i]]-1, i-1, 1) > A[i]){
            ans.insert("121");
        }
        ck[A[i]] = i+1;
    }
    ck.clear();

    set<int> st;
    vector<int> rLmax(N), rGmin(N), lLmax(N), lGmin(N);

    for(int i = N-1; i >= 0; i--){
        auto val = st.lower_bound(A[i]);
        if (val != st.begin()){
            val--;
            rLmax[i] = *val;
        }
        else rLmax[i] = -1;
        val = st.lower_bound(A[i]+1);
        if (val != st.end()) {
            rGmin[i] = *val;
        }
        else rGmin[i] = 1e9+10;
        st.insert(A[i]);
    }
    st.clear();


    for(int i = 0; i < N; i++){
        auto val = st.lower_bound(A[i]);
        if (val != st.begin()){
            val--;
            lLmax[i] = *val;
        }
        else lLmax[i] = -1;
        val = st.lower_bound(A[i]+1);
        if (val != st.end()) {
            lGmin[i] = *val;
        }
        else lGmin[i] = 1e9+10;
        st.insert(A[i]);
    }
    st.clear();

    //for(int i = 0; i < N; i ++){
    //    cout << rLmax[i] << ' ' << rGmin[i] << ' ' << lLmax[i] << ' ' << lGmin[i] << '\n';
    //}

    for(int i = 0; i < N; i++){

        if (rGmin[i] > A[i] && rGmin[i] < getVal(0, sn-1, 1, 0, i-1, 1)) {
            ans.insert("312");
        }
        if(lGmin[i] > A[i] && lGmin[i] < getVal(0, sn-1, 1, i+1, N-1, 1)){
            ans.insert("213");
        }
        if (rLmax[i] < A[i] && rLmax[i] > getVal(0, sn-1, 1, 0, i-1, 0)) {
            ans.insert("132");
        }
        if(lLmax[i] < A[i] && lLmax[i] > getVal(0, sn-1, 1, i+1, N-1, 0)){
            ans.insert("231");
        }
    }

    for(auto f : ans) cout << f << '\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    solve();
    return 0;
}
