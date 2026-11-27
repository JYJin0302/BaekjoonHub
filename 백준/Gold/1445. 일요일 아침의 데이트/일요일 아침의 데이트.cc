#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a) for(i = 0; i < (a); i++)

struct C{
    int cnt1, cnt2;
    
    C() : cnt1(0), cnt2(0){}
    C(int a, int b) : cnt1(a), cnt2(b){}
    bool operator<(const C& a) const{
        if (a.cnt1 == cnt1) return cnt2 > a.cnt2;
        return cnt1 > a.cnt1;
    }
};

int n, m;
C dist[51][51];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool inGrid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main(){
    
    
    cin >> n >> m;
    
    vector<string> A(n);
    for(auto& i : A) cin >> i;
    
    // 시작점찾기
    int si, sj;
    FOR(si, n){ 
        FOR(sj, m) if (A[si][sj] == 'S') break;
        if (A[si][sj] == 'S') break;
    }
    
    // 쓰레기 옆자리표시
    int i, j;
    FOR(i, n) FOR(j, m){
        if (A[i][j] == '.'){
            
            for (int k = 0; k < 4; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                if (inGrid(ni, nj) && A[ni][nj] == 'g') A[i][j] = 'p';
            }
        }
    }

    FOR(i, n) FOR(j, m) dist[i][j] = {10000, 10000};
    
    priority_queue<tuple<C, int, int>> pq;
    pq.push({{0, 0}, si, sj});
    dist[si][sj] = {0, 0};
    
    while(!pq.empty()){
        
        C tc;
        int a, b;
        tie(tc, a, b) = pq.top();
        pq.pop();
    
        
        if (A[a][b] == 'F'){
            cout << tc.cnt1 << ' ' << tc.cnt2 << '\n';
            return 0;
        }
        
        for(int i = 0; i < 4; i++){
            int na = a + dx[i];
            int nb = b + dy[i];
            
            if (!inGrid(na, nb)) continue;
            
            C nc = tc;
            if (A[na][nb] == 'g') nc.cnt1++;
            if (A[na][nb] == 'p') nc.cnt2++;
            
            if (dist[na][nb] < nc){
                dist[na][nb] = nc;
                pq.push({nc, na, nb});
            }
        }
    }
}