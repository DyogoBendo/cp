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

// Matriz

const ll MOD = 1e9;
template<typename T> struct matrix : vector<vector<T>> {
	int n, m;

	void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cout << (*this)[i][j] << " ";
			cout << endl;
		}
	}

	matrix(int n_, int m_, bool ident = false) :
			vector<vector<T>>(n_, vector<T>(m_, 0)), n(n_), m(m_) {
		if (ident) {
			assert(n == m);
			for (int i = 0; i < n; i++) (*this)[i][i] = 1;
		}
	}
	matrix(const vector<vector<T>>& c) : vector<vector<T>>(c),
		n(c.size()), m(c[0].size()) {}
	matrix(const initializer_list<initializer_list<T>>& c) {
		vector<vector<T>> val;
		for (auto& i : c) val.push_back(i);
		*this = matrix(val);
	}

	matrix<T> operator*(matrix<T>& r) {
		assert(m == r.n);
		matrix<T> M(n, r.m);
		for (int i = 0; i < n; i++) for (int k = 0; k < m; k++)
			for (int j = 0; j < r.m; j++) {
				T add = (*this)[i][k] * r[k][j];
				M[i][j] += add%MOD;
				if (M[i][j] >= MOD) M[i][j] -= MOD;
			}
		return M;
	}

	matrix<T> operator^(ll e){
		matrix<T> M(n, n, true), at = *this;
		while (e) {
			if (e&1) M = M*at;
			e >>= 1;
			at = at*at;
		}
		return M;
	}
	void apply_transform(matrix M, ll e){
		auto& v = *this;        
		while (e) {            
			if (e&1)v = M*v;                
            
			e >>= 1;
			M = M*M;
		}
	}
};

void solve(){
    ll k, n;
    cin >> k;
    vector<ll> b(k), c(k);
    for(int i = 0; i < k; i++) cin >> b[i];
    for(int i = k - 1; i >= 0; i--) cin >> c[i];
    cin >> n;
    n--;

    matrix<ll> transform(k, k);
    for(int i = 0; i < k - 1; i++) transform[i][i+1] = 1;
    transform[k-1] = c;
    
    matrix<ll> base(k, 1);
    for(int i = 0; i < k; i++) base[i][0] = b[i];    
        
    base.apply_transform(transform, n);
    cout << base[0][0] << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}