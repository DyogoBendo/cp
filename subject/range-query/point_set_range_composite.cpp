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

template <typename T>
class SegmentTree {
public:
    int n;
    vector<T> seg;

    T neutral(){
        mint a = 1;
        mint b = 0;
        return make_pair(a, b);
    }

    pair<mint, mint> combine(pair<mint, mint> l, pair<mint, mint> r){
        return make_pair(l.first * r.first, r.first * l.second + r.second);
    }

    T build(const vector<T> &v, int p, int l, int r) {
        if (l == r) return seg[p] = v[l];
        
        int mid = (l + r) / 2;
        T left = build(v, 2*p, l, mid);
        T right = build(v, 2*p + 1, mid + 1, r);
        return seg[p] = combine(left, right);
    }

    T update(int k, T u, int p, int l, int r) {
        if (l == r) return seg[p] = u;

        int mid = (l + r) / 2;
        T left = seg[2*p], right = seg[2*p + 1];

        if (k <= mid)left = update(k, u, 2*p, l, mid);
        else right = update(k, u, 2*p + 1, mid + 1, r);
        
        return seg[p] = combine(left, right);
    }

    T query(int a, int b, int p, int l, int r) {
        if (l > b || r < a) return neutral();
        if (l >= a && r <= b) return seg[p];
        int mid = (l + r) / 2;
        T left = query(a, b, 2*p, l, mid);
        T right = query(a, b, 2*p + 1, mid + 1, r);

        dbg(left.first, left.second, right.first, right.second);        
        return combine(left, right);
    }

    SegmentTree(const vector<T> &v) {
        n = (int)v.size();
        seg.assign(4*n, neutral());
        if (n > 0) build(v, 1, 0, n-1);
    }

    void update(int idx, T val) {
        update(idx, val, 1, 0, n-1);
    }

    T query(int l, int r) {
        return query(l, r, 1, 0, n-1);
    }
};


signed main(){
    darvem;

    int n, q;
    cin >> n >> q;

    vector<pair<mint, mint>> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    SegmentTree<pair<mint, mint>> seg(v);
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if(a == 0){
            pair<mint, mint> p;
            p.first = c;
            p.second = d;            
            seg.update(b, p);
        } else{
            dbg(c, d);
            auto result = seg.query(b, c - 1);
            dbg(result.first, result.second);
            mint ans = result.first * d + result.second;
            cout << ans << endl;
        }   
    }
}