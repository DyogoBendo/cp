#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MAX = 2e5;

// Aritmetica Modular
//
// O mod tem q ser primo

template<int p> struct mod_int {
	ll expo(ll b, ll e) {
		ll ret = 1;
		while (e) {
			if (e % 2) ret = ret * b % p;
			e /= 2, b = b * b % p;
		}
		return ret;
	}
	ll inv(ll b) { return expo(b, p-2); }

	using m = mod_int;
	int v;
	mod_int() : v(0) {}
	mod_int(ll v_) {
		if (v_ >= p or v_ <= -p) v_ %= p;
		if (v_ < 0) v_ += p;
		v = v_;
	}
	m& operator +=(const m& a) {
		v += a.v;
		if (v >= p) v -= p;
		return *this;
	}
	m& operator -=(const m& a) {
		v -= a.v;
		if (v < 0) v += p;
		return *this;
	}
	m& operator *=(const m& a) {
		v = 1LL * v *(a.v) % p;
		return *this;
	}
	m& operator /=(const m& a) {
		v = v * inv(a.v) % p;
		return *this;
	}
	m operator -(){ return m(-v); }
	m& operator ^=(ll e) {
		if (e < 0) {
			v = inv(v);
			e = -e;
		}
		v = expo(v, e);
		// possivel otimizacao:
		// cuidado com 0^0
		// v = expo(v, e%(p-1)); 
		return *this;
	}
	bool operator ==(const m& a) { return v == a.v; }
	bool operator !=(const m& a) { return v != a.v; }

	friend istream& operator >>(istream& in, m& a) {
		ll val; in >> val;
		a = m(val);
		return in;
	}
	friend ostream& operator <<(ostream& out, m a) {
		return out << a.v;
	}
	friend m operator +(m a, m b) { return a += b; }
	friend m operator -(m a, m b) { return a -= b; }
	friend m operator *(m a, m b) { return a *= b; }
	friend m operator /(m a, m b) { return a /= b; }
	friend m operator ^(m a, ll e) { return a ^= e; }
};

typedef mod_int<(int)998244353> mint;
typedef array<array<mint, 2>, 2> matrix;
matrix operator*(const matrix& a, const matrix& b) {
    matrix ans = {{{mint(0), mint(0)}, {mint(0), mint(0)}}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                ans[i][j] += a[i][k] * b[k][j];
            }            
        }        
    }
    return ans; 
}


// SegTree
//
// Recursiva com Lazy Propagation
// Query: soma do range [a, b]
// Update: soma x em cada elemento do range [a, b]
// Pode usar a seguinte funcao para indexar os nohs:
// f(l, r) = (l+r)|(l!=r), usando 2N de memoria
//
// Complexidades:
// build - O(n)
// query - O(log(n))
// update - O(log(n))

#define M0 {{{mint(1), mint(0)}, {mint(1), mint(1)}}}
#define M1 {{{mint(1), mint(1)}, {mint(1), mint(0)}}}

namespace seg {
	ll lazy[4*MAX];
    matrix seg[4*MAX], inv[4*MAX];
	int n;
    string v;

	pair<matrix, matrix> build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r){
            if(v[l] == '1') seg[p] = M1, inv[p] = M0;
            else seg[p] = M0, inv[p] = M1;
            return {seg[p], inv[p]};
        } 
		int m = (l+r)/2;
        auto lt = build(2*p, l, m), rt = build(2*p+1, m+1, r);
        seg[p] = (lt.first * rt.first), inv[p] = (lt.second*rt.second);
		return {seg[p], inv[p]};
	}
	void build(int n2, string s) {
		n = n2, v = s;
		build();
	}
	void prop(int p, int l, int r) {
        if(lazy[p]){
            swap(seg[p], inv[p]);
            if (l != r) lazy[2*p] ^= 1 , lazy[2*p+1] ^= 1;
            lazy[p] = 0;
        }
	}
	matrix query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return {{{mint(1), mint(0)}, {mint(0), mint(1)}}};
		int m = (l+r)/2;
		return (query(a, b, 2*p, l, m)*query(a, b, 2*p+1, m+1, r));
	}
	pair<matrix, matrix> update(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] ^= 1;
			prop(p, l, r);
			return {seg[p], inv[p]};
		}
		if (b < l or r < a) return {seg[p], inv[p]};
		int m = (l+r)/2;
        auto lt = update(a, b, 2*p, l, m), rt = update(a, b, 2*p+1, m+1, r);
        seg[p] = (lt.first* rt.first), inv[p] = (lt.second* rt.second); 
		return {seg[p], inv[p]};
	}
};

void print(matrix m){
    cout << "[" << m[0][0] << ", " << m[0][1] << "]" << endl << "[" << m[1][0] << ", " << m[1][1]  <<"]"<< endl;
}

mint calc(matrix m, mint x, mint y){    
    return m[0][0] * x + m[1][0] * y;
}

signed main(){
    darvem;

    int n, a, b;
    cin >> n >> a >> b;

    if(b > a) swap(a, b);
    mint x(a), y(b);

    string s;
    cin >> s;

    int q;
    cin >> q;

    seg::build(n, s);    

    matrix m0 = M0, m1 = M1;        
    while(q--){
        int l, r;
        cin >> l >> r;
        l --; r--;
        seg::update(l, r);

        cout << calc(seg::query(0, n-1), x, y) << endl;
    }
    
}