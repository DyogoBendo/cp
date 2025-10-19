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
#define int long long

const int MAX = 1e7 + 10;

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

typedef mod_int<(int)1e9+7> mint;

int testcase = 0;
vector<int> primes;
mint fat[100];

void setIO(string s) {	
	freopen((s + ".txt").c_str(), "w", stdout);
}

void print(int ans){
    cout << "Case #"<<testcase << ": " << ans << endl;
}

void init(){
    primes.push_back(2);
    vector<int> visited(MAX);
    for(int i = 2; i * i < MAX; i+= 2) visited[i] = 1;
    for(int i = 3; i < MAX; i+= 2){
        if(visited[i]) continue;
        primes.push_back(i);
        for(int j = i; j < MAX; j += i) visited[j] = 1;
    }

    fat[0] = 1;
    for(int i = 1; i < 100; i++) fat[i] = fat[i-1] * i;

}


vector<int> get_divisors(int x){
    vector<int> divisors;
    for(int i = 1; i * i <= x;i++){
        if(x %i == 0){
            divisors.push_back(i);
            int y = x/i;
            if(y != i) divisors.push_back(y);
        }
    }
    return divisors;
}

mint calc(vector<pair<int, int>> factors, mint size){
    mint tot = 1;
    for(auto [p, cnt] : factors){        
        tot *= size^cnt;
        tot /= fat[cnt];
    }    

    return tot;
}

mint calc2(ll b, ll size){
    vector<pair<int, int>> factors;
    int bp = b;
    for(auto p : primes){
        if(p > bp) break;
        int cnt= 0;
        while(bp %p == 0){
            cnt++;
            bp /= p;
        }        
        if(cnt) factors.push_back({p, cnt});
    }

    if(bp > 1) factors.push_back({bp, 1});

    mint ans = calc(factors, size);

    dbg(b, size, ans);

    return ans;
}

void solve(){
    int n, a, b;

    cin >> n >> a >> b;    

    vector<int> all_divisors = get_divisors(b);

    mint tot = calc2(b, 2*n);
    for(auto x : all_divisors) if(x > a){
        tot -= calc2(x, n) * calc2(b/x, n);
    }

    cout << tot << endl;
}

signed main(){
    init();
	darvem;
    //setIO("output");
    int t;
    cin >> t;
    while(t--){
        testcase++;
        solve();
    }
}