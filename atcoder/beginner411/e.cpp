// Aritmetica Modular
//
// O mod tem q ser primo

#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

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

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<int> dices(n);

    vector<tuple<int, int, int>> oc;

    for (int i = 0; i < n; i++)
    {
        map<int, int> mp;
        for (int j = 0; j < 6; j++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }

        for (auto [x, o] : mp)
        {
            oc.push_back({x, o, i});
        }
        
    }

    sort(oc.begin(), oc.end());

    vector<int> dices_cases(n, 0);
    int cnt = 0;

    mint prob(1);
    mint ans(0);

    for (auto [value, ap, idx] : oc)
    {        
        if(dices_cases[idx] == 0) cnt ++;

        mint prev = dices_cases[idx];
        prev/= 6;

        if(cnt == n){
            mint no_curr_dice = prob;
            if(prev != 0){
                no_curr_dice /= prev;
            }

            mint curr = ap;            
            curr /= 6;            

            ans += no_curr_dice * curr * value;

        }

        if(prev != 0){
            prob/= prev;
        }
        dices_cases[idx] += ap;

        prev = dices_cases[idx];
        prev /= 6;
        prob *= prev;
    }

    cout << ans << endl;
}
