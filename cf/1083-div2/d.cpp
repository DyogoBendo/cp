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

const int MAXN=  5e5 + 10, MAX2 = 20;

int ap[MAXN], v[MAXN], dp[MAXN], n;

namespace sparse {
	int m[MAX2][MAXN], n;
	void build(int n2, int* v) {
		n = n2;
		for (int i = 0; i < n; i++) m[0][i] = v[i];
		for (int j = 1; (1<<j) <= n; j++) for (int i = 0; i+(1<<j) <= n; i++)
			m[j][i] = max(m[j-1][i], m[j-1][i+(1<<(j-1))]);
	}
	int query(int a, int b) {
		int j = __builtin_clz(1) - __builtin_clz(b-a+1);
		return max(m[j][a], m[j][b-(1<<j)+1]);
	}
}


int calc(int l, int r){ 
    if(r <= l) return 0;
    if(r < 1)  return 0;
    if(l > n) return 0;
    int x = sparse::query(l, r);
    int pos = ap[x];    
    int dl = pos - l;
    int dr = r - pos;    
        
    return min(dl + calc(pos+1, r), dr + calc(l, pos-1));
        
}

void solve(){    
    cin >> n;

    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) ap[v[i]] = i;

    sparse::build(n, v);

    for(int i = 0; i<= n; i++) dp[i] = -1;

    int l = 0, r = n-1;

    cout << calc(l, r) << endl;
}   


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}