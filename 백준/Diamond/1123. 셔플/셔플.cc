#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 600921647;
bool G[15][15];
int cnt[15][15];
int n, m;

vector<vector<ll>> mult(vector<vector<ll>>& v1, vector<vector<ll>>& v2) {
    int s = v1.size();
    vector<vector<ll>> res(s, vector<ll>(s));
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            for (int k = 0; k < s; k++) {
                res[i][j] += v1[i][k] * v2[k][j] % mod;
                res[i][j] %= mod;
            }
        }
    }
    return res;
}
vector<ll> mult(vector<ll>& v1, vector<vector<ll>>& v2){
	int s = (int)v1.size();

	vector<ll> res(s);
	for(int i = 0; i < s;i++){
		for(int j = 0 ;j < s; j++){
			res[j] += v1[i] * v2[i][j] % mod;
			res[j] %= mod;
		}
	}
	return res;
}

vector<vector<ll>> base[33];
vector<ll> dp(90), tdp;

ll getVal(ll x) {
	if (x == 0) return 0;
	if (x <= 9){
		return dp[(x-1)*10 + 9];
	}
	tdp = dp;

	ll nd = x - 9;
	for(int i =0 ; i < 31; i++){
		if(nd & (1 << i)){
			tdp = mult(tdp, base[i]);
		}
	}
	return tdp[89];
}

void solve() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cnt[a][b]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'Y') G[i][j] = 1;
        }
    }

    ll A, B;
    cin >> A >> B;

	for(int i = 1; i <= 9; i++){
		for(int j = 0; j < 9; j++){
			ll val = cnt[j][i];

			dp[(i-1) * 10 + j] += val;
			for(int ti = 1; ti < i; ti++){
				for(int tj = 0; tj < 9; tj++){
					if (!G[tj][j]) continue;
					ll nv = cnt[j][ti];
					(dp[(i-1)*10 + j] += dp[(i-ti-1) * 10 + tj] * nv % mod) %= mod;
				}
			}
		}
	}
	for(int i = 1; i <= 9; i++){
		ll val = 0;
		for(int j =0 ; j< 9; j ++) {
			val = (val + dp[(i-1) * 10 + j]) % mod;
		}
		if(i > 1) val += dp[(i-2) * 10 + 9];
		val %= mod;
		dp[(i-1) * 10 + 9] = val;
	}

	
	vector<vector<ll>> bb(90, vector<ll>(90));
	for(int i = 1; i < 9; i++){
		for(int j = 0; j < 9; j++){
			bb[i*10+ j][(i-1)*10+j]++;
		}
	}
	bb[89][89] = 1;

	for(int i = 1; i <= 9; i++){
		for(int j = 0; j < 9; j++){
			ll val = cnt[j][i];
			for(int tj =0 ; tj < 9 ;tj++){
				if(!G[tj][j]) continue;
				(bb[(8-i+1)*10 + tj][80+j] += val) %= mod;
				(bb[(8-i+1)*10 + tj][89] += val) %= mod;
			}
		}
	}

	base[0] = bb;
	for(int i = 1; i <32; i++){
		base[i] = mult(base[i-1] ,base[i-1]);
	}
	


    ll ans = (getVal(B) - getVal(A - 1) + mod) % mod;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}