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
		v = 1LL * v * (a.v) % p;
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

const int MAX = 1e5 + 10;

struct node{
    mint val = 0;
    mint sum = 0;
    int tam = 0;
};

namespace seg {
	node seg[4*MAX];
    mint lazy[4*MAX];
	int n;
    node* v;

    node merge(node a, node b){
        node r;
        r.val = a.sum * b.sum + a.val + b.val;        

        r.sum = a.sum + b.sum;
        r.tam = a.tam + b.tam;
        return r;
    }    

	node build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, node* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
        mint tam = (r-l+1);            
        if(r-l+1 > 1){
            seg[p].val += lazy[p] * (tam - 1) * seg[p].sum + ((tam * (tam - 1)) / 2) * lazy[p] * lazy[p];
        }
        seg[p].sum += lazy[p]*tam;		        

		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}

	node query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b){            
            return seg[p];
        } 
		if (b < l or r < a) return node();
		int m = (l+r)/2;

        auto qr = merge(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
        
		return qr;
	}
	node update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = merge(update(a, b, x, 2*p, l, m),
			update(a, b, x, 2*p+1, m+1, r));
	}
};

node v[MAX];
void solve(){
    int n, q;
    cin >> n >> q;

    seg::build(n+1, v);

    while(q--){
        int l, r, a;
        cin >> l >> r >> a;

        seg::update(l, r, a);
        cout << seg::query(l, r).val << endl;
    }
}


signed main(){
    darvem;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}