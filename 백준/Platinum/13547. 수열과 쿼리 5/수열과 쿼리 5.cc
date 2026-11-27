#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

struct Q{
    int idx, s, e;
};

int sn;
bool cmp(Q& A, Q& B){
    if (A.s / sn == B.s / sn) return A.e < B.e;
    return A.s /sn < B.s /sn;
}

int val = 0;
int cnt[1000001];

void add_num(int n){
    if (cnt[n] == 0) val++;
    cnt[n]++;
}
void sub_num(int n){
    if (cnt[n] == 1) val--;
    cnt[n]--;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    sn = sqrt(n);
    
    vector<int> A(n+1);
    for(int i = 1; i <= n; i++) cin >> A[i];
    
    int m;
    cin >> m;
    vector<Q> q(m);
    for(int i = 0; i < m;i++){
        int a, b;
        cin >> a >> b;
        q[i].s = a, q[i].e = b;
        q[i].idx = i;
    }
    sort(q.begin(), q.end(), cmp);
    
    vector<int> ans(m);
    int l = q[0].s, r = q[0].e;
    
    for (int i = l; i <= r; i++){
        add_num(A[i]);
    }
    ans[q[0].idx] = val;
    
    
    for(int i = 1; i < m; i++){
        
        int px = q[i].s, py = q[i].e;
        
        for (int j = l; j < px; j++) sub_num(A[j]);
        for (int j = px; j < l; j++) add_num(A[j]);
            
        for (int j = r + 1; j <= py; j++) add_num(A[j]);
        for (int j = py + 1; j <= r; j++) sub_num(A[j]);
        
        ans[q[i].idx] = val;
        l = px, r = py;
    }
    
    for(int i : ans) cout << i << '\n';
    
}