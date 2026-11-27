#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()



int A[6][6];
int B[6][6];
int T[10];


int pre[1000000];

int cur[6];
void setup(){

    for(int a = 0;a < 10; a++){
        for(int b= 0; b < 10; b++){
            for(int c= 0;c < 10; c++){
                for(int d = 0; d < 10; d++){
                    for(int e =0; e < 10; e++){

                        int mx = 0;
                        for(int x = 0;x < 10; x++){
                            int val = x;
                            val += (x + a) % 10;
                            val += (x + a + b) % 10;
                            val += (x + a + b + c) % 10;
                            val += (x + a + b + c + d) % 10;
                            val += (x + a + b + c + d + e) % 10;
                            mx = max(mx, val);
                        }

                        pre[a * 10000 + b * 1000 + c * 100 + d * 10 + e] = mx;
                    }
                }
            }
        }
    }
}

void solve(){
    
    int n = 6;

    for(int i =0; i < 6; i++){
        for(int j = 0; j <6; j++){
            cin >> A[i][j];
        }
    }

    setup();

    int ans = 0;
    for(int c1 = 0; c1 < 10; c1++){
        T[1] = c1;
        for(int c2 = 0 ;c2 < 10; c2++){
            T[2] = c2;
            for(int c3 = 0; c3 < 10; c3++){
                T[3] = c3;
                for(int c4 = 0; c4 < 10; c4++){
                    T[4] = c4;
                    for(int c5 = 0;c5 < 10; c5++){
                        T[5] = c5;
                        for(int d1 =0; d1 < 10; d1++){
                            for(int d2= 0; d2 < 10; d2++){


                                int val = 0;
                                for(int a = 0;a < 6; a++){
                                    for(int b = 0;b < 6;b++){
                                        cur[b] = A[a][b] + T[b] + (a == b ? d1 : 0) + (a + b == 5 ? d2 : 0);
                                        cur[b] %= 10;
                                    }
                                    
                                    int ix = 0;
                                    for(int  b = 1; b < 6; b++){
                                        int off = (cur[b] - cur[b-1] + 10) % 10;
                                        ix = ix * 10 + off;
                                    }

                                    val += pre[ix];
                                    
                                }

                                ans = max(ans, val);
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << '\n';

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}
