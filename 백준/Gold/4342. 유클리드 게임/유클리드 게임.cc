#include <bits/stdc++.h>
using namespace std;

int cnt;
void game(int x, int y){
    if (x / y >= 2 || x % y == 0) return;
    cnt++;
    game(y, x%y);
}
int main(){
    int n, m;
    cin >> n >> m;
    while(n || m){
        cnt = 0;
        game(max(n, m), min(n, m));
        if (cnt % 2)cout << "B wins\n";
        else cout << "A wins\n";
        cin >> n >> m;
    }
}