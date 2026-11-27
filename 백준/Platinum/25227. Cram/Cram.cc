#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define all(x) x.begin(), x.end()
#define mp make_pair
#define pi pair<int, int>

int encode(char c){
    if (c >= 'a' && c <= 'z') return c - 'a';
    if (c >= 'A' && c <= 'Z') return (c - 'A') + 26;
    return 52;
}

vector<int> getfail(const vector<int>& A, bool order = false){
    vector<int>a = A;
    a.push_back(-1);
    int N = a.size();
    vector<int> sa(N), c(N);
    vector<pi> tmp(N), new_tmp(N);
    for(int i = 0 ;i < N; i++){
        tmp[i] = mp(a[i], i);
    }
    sort(all(tmp));
    for(int i = 0; i < N; i++){
        sa[i] = tmp[i].second;
    }
    c[sa[0]] = 0;
    for(int i = 1; i < N; i++){
        if(tmp[i].first == tmp[i-1].first) {
            c[sa[i]] = c[sa[i-1]];
        }
        else c[sa[i]] = c[sa[i-1]] + 1;
    }

    for(ll k = 1; k < N; k <<= 1){
        vector<pair<pair<int, int>, int>> tmp(N), new_tmp(N);
        for (int i = 0 ;i < N; i++){
            tmp[i].first = {c[(sa[i] - k + N)% N], c[sa[i]]};
            tmp[i].second = (sa[i] - k + N) % N;
        }

        vector<int> cnt(N), p(N);
        for(int i = 0; i < N; i++){
            cnt[tmp[i].first.first]++;
        }

        for(int i = 1;i < N; i++){
            p[i] = p[i-1] + cnt[i-1];
            if (p[i] == N) break;
        }

        for(int i = 0; i < N; i++){
            new_tmp[p[tmp[i].first.first]] = tmp[i];
            p[tmp[i].first.first]++;
        }
        swap(tmp, new_tmp);

        for(int i = 0; i < N; i++) sa[i] = tmp[i].second;
        c[sa[0]] = 0;
        for(int i = 1; i <  N; i++){
            if (tmp[i].first == tmp[i-1].first){
                c[sa[i]] = c[sa[i-1]];
            }
            else{
                c[sa[i]] = c[sa[i-1]] + 1;
            }
        }
        if(c[sa[N-1]] == N-1) break;
    }
    if (order) return c;
    return sa;
}

vector<int> sa, ord;

vector<int> get_lcp(const vector<int>& A){
    vector<int> a = A;
    a.push_back(-1);
    int N = a.size();
    vector<int> lcp(N);

    int d = 0;
    for(int j = 0; j < N-1; j++){
        int x = ord[j]; int i = sa[x-1];
        while(a[j+d] == a[i+d]) ++d;
        lcp[x] = d;
        d = max(d-1, 0);
    }
    return lcp;
}

int nxt[101010];

int seg[303030]; // 가장 가까운 왼/오른 index

void update(int l, int r, int n, int u, int val){
    if (l > u || r < u) return;
    if (l == u && r == u){
        seg[n] = val;
        return;
    }
    int md = (l+r)>>1;
    update(l, md, n*2, u, val);
    update(md+1,r, n*2+1, u, val);
    seg[n] = seg[n*2] + seg[n*2+1];
}

int getIdx(int l, int r, int n, int ul, int ur, bool dir){

    // [ul, ur] 사이에서 dir쪽 가장 먼 index
    // dir =1 오른쪽, dir= 0, 왼쪽
    if (seg[n] == 0) return -1;
    if (l > ur || r < ul) return -1;
    if (l == r) return l;

    int md = (l+r)>>1;
    if (dir){
        int ret = getIdx(md+1, r, n*2+1, ul, ur, dir);
        if (ret != -1) return ret;
        return getIdx(l, md, n*2, ul, ur, dir);
    }
    else{
        int ret = getIdx(l, md, n*2, ul, ur, dir);
        if (ret != -1) return ret;
        return getIdx(md+1, r, n*2+1, ul, ur, dir);
    }
}

vector<int> lcp;
int seg2[303030]; // lcp minimum;

void init(int l, int r, int n){
    if(l == r) {
        seg2[n] = lcp[l];
        return;
    }
    int md =(l+r)>>1;
    init(l, md, n*2);
    init(md+1,r, n*2+1);
    seg2[n] = min(seg2[n*2], seg2[n*2+1]);
}

int getMin(int l, int r, int n, int sl, int sr){
    if (l > sr || r < sl) return 101010;
    if (l >= sl && r <= sr) return seg2[n];
    int md = (l+r)>>1;
    return min(getMin(l, md, n*2, sl, sr), getMin(md+1, r, n*2+1, sl, sr));
}

void solve(){
    
    string s;
    getline(cin, s);

    int n = (int)s.size();

    vector<int> A;
    for(auto f : s) A.push_back(encode(f));

    sa = getfail(A);    // 1-index
    ord = getfail(A, true); // 0-index

    lcp = get_lcp(A); // 1-index
    // for(auto f :lcp) cout << f << ' ';
    // cout << endl;
    init(1, n, 1);


    for(int i = 0; i < n; i++){
        // get nxt[i];

        //cout << "Go: " << i << ' ' << ord[i] << endl;
        int pos = ord[i];
        int ldx = getIdx(1, n, 1, 1, pos-1, 1);
        
        if (ldx != -1){
            int v = getMin(1, n, 1, ldx+1, pos);
            nxt[i] = max(nxt[i], v);
            //cout << "Ldx: "<< ldx << ' ' << v << endl;
        }
        int rdx = getIdx(1, n, 1, pos+1, n, 0);
        if (rdx != -1){
            int v = getMin(1, n, 1, pos+1, rdx);
            nxt[i] = max(nxt[i], v);
            //cout << "rdx: " << rdx << ' ' << v << endl;
        }

        update(1, n, 1, pos, 1);
    }

    // for(int i = 0; i < n;i++) cout << nxt[i] << ' ';
    // cout << '\n';

    set<pair<int, int>> st;
    st.insert(mp(0, 0));

    vector<int> dist(n + 1, -1);
    while(!st.empty()){
        auto [a,b] =*st.begin();
        st.erase(st.begin());

        if (dist[b] != -1) continue;
        dist[b] = a;

        if (b < n && dist[b+1] == -1){
            st.insert(mp(a+1, b+1));
        }
        if (b < n && nxt[b+1]){
            int nb = b + nxt[b+1];
            if (dist[nb] == -1){
                st.insert(mp(a + 3, nb));
            }
        }
    }
    
    cout << dist[n] << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
