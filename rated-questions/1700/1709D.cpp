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

namespace sparse {
    const int MAX2 = 30;
    const int MAX = 2e5 + 10;
	int ma[MAX2][MAX], n;
	void build(int n2, vector<int> v) {
		n = n2;
		for (int i = 0; i < n; i++) ma[0][i] = v[i];
		for (int j = 1; (1<<j) <= n; j++) for (int i = 0; i+(1<<j) <= n; i++)
			ma[j][i] = max(ma[j-1][i], ma[j-1][i+(1<<(j-1))]);
	}
	int query(int a, int b) {
        if(a > b) swap(a, b);        
		int j = __builtin_clz(1) - __builtin_clz(b-a+1);
		return max(ma[j][a], ma[j][b-(1<<j)+1]);
	}
}

void solve(){
    int n, m;
    cin >> n >>m;

    vector<int> v(m);
    for(int i = 0; i < m; i++) cin >> v[i];

    sparse::build(m, v);

    int q;
    cin >> q;

    while(q--){
        int xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;

        int diff_x = abs(xs - xf);
        int diff_y = abs(ys - yf);

        if(diff_x % k or diff_y % k){
            cout << "NO" << endl;
            continue;
        } 

        ys--; yf--;
        int mx = sparse::query(ys, yf);

        if(mx >= xs){
            int diff_h = mx - xs + 1;
            int moves = diff_h/k + (diff_h % k > 0);                        
            if(xs + moves *k > n){
                cout << "NO" << endl;
                continue;
            } 
        }
        cout << "YES" << endl;
    }
}


signed main(){
    darvem;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}