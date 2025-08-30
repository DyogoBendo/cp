#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

int tot(int n) {
	int ret = n;

	for (int i = 2; i*i <= n; i++) if (n % i == 0) {
		while (n % i == 0) n /= i;
		ret -= ret / i;
	}
	if (n > 1) ret -= ret / n;

	return ret;
}

ll pow(ll x, ll y, ll m) {
	if (!y) return 1;
	ll ans = pow(x*x%m, y/2, m);
	return y%2 ? x*ans%m : ans;
}

signed main(){
    darvem;

    int n, e, c;
    cin >> n >> e >> c;

    int t1 = tot(n);
    int t2 = tot(t1);

    int d = pow(e, t2-1, t1);
    cout << pow(c, d, n) << endl;
}