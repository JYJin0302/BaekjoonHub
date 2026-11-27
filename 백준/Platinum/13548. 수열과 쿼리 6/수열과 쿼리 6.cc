#include <bits/stdc++.h>
using namespace std;

int n, sn;
struct Q{
    int s, e, idx;
    
    bool operator<(Q& other){
        if (s/sn == other.s/sn) return e < other.e;
        return s/sn < other.s/sn;
    }
};

int val = 0;
int cnt_num[100001];
int cnt_val[100001];

void add_num(int x){
    int tval = cnt_num[x];
    cnt_val[tval]--;
    cnt_val[tval+1]++;
    cnt_num[x]++;
    val = max(val, tval+1);
}
void sub_num(int x){
    int tval = cnt_num[x];
    cnt_val[tval]--;
    cnt_val[tval-1]++;
    cnt_num[x]--;
    if (cnt_val[val] == 0) val--;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    sn = sqrt(n);
    
    vector<int> A(n+1);
    for(int i = 1; i <= n; i++) cin >> A[i];
    
    int m;
    cin >> m;
    
    vector<Q> q(m);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        
        q[i].s = a, q[i].e = b;
        q[i].idx = i;
    }
    
    sort(q.begin(), q.end());
    
    vector<int> ans(m);
    int l = q[0].s, r = q[0].e;
    for (int i = l; i <= r; i++){
        add_num(A[i]);
    }
    ans[q[0].idx] = val;
    
    for(int i = 1; i < m; i++){
        
        int ns = q[i].s, ne = q[i].e;
        
        for (int j = ns; j < l; j++) add_num(A[j]);
        for (int j = l; j < ns; j++) sub_num(A[j]);
        
        for (int j = ne + 1; j <= r; j++) sub_num(A[j]);
        for (int j = r + 1; j <= ne; j++) add_num(A[j]);
        
        ans[q[i].idx] = val;
        l = ns, r = ne;
    }
    
    for(auto i : ans) cout << i << '\n';
}