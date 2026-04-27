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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;


#define int ll

struct Bit {
	int n;
	vector<ll> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(int i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	ll pref(int i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1); 
	}
	int upper_bound(ll x) {
		int p = 0;
		for (int i = __lg(n); i+1; i--) 
			if (p + (1<<i) <= n and bit[p + (1<<i)] <= x)
				x -= bit[p += (1 << i)];
		return p;
	}
};

signed main(){
    darvem;

    int n, b, r, w;
    cin >> n >> b >> r >> w;

    vector<int> d(b);
    for(int i = 0; i < b; i++) cin >> d[i];

    vector<int> pd(b+1);
    for(int i = 0; i < b; i++) pd[i+1] = pd[i] + d[i];

    vector<int> destination(n);
    for(int i = 0; i < n; i++) cin >>destination[i];

    ll lo = 0, hi = 1e18;

    auto check = [&](ll x){
        int cnt_bus_wait = 0;           
        //cout << "--------------" << endl;       
        Bit b1(b+2), b2(b+2);
        vector<int> visited(b+2);  
        for(int i = 0, j = 0; i < n; i = j, cnt_bus_wait++){            
            dbg(i, j, x);
            ll cost = cnt_bus_wait * r;
            int lst_stop = 0;        
            vector<int> added;
            while(j < n){            
                dbg(j, cost);                
                // we have to stop at this new point, so everybody that is after this one will have to stop here
                if(!visited[destination[j]]){
                    int all_after = b2.query(destination[j], b+1);
                    cost += 2*w*all_after;
                    b1.update(destination[j], 1);
                    visited[destination[j]] = 1;
                }
                
                added.push_back(destination[j]);
                b2.update(destination[j], 1);
                int unique_before = b1.query(0, destination[j] - 1);

                dbg(j, destination[j], unique_before, 2*w*(unique_before+1));
                cost += 2*w*(unique_before+1); // this one will stop at every parade before it

                dbg(j, cost);
                if(destination[j] > lst_stop){
                    cost += pd[destination[j]] - pd[lst_stop];
                    lst_stop = destination[j];
                }                 
                dbg(j, cost);                
                if(cost <= x) j++;
                else break;                
            }            
            for(auto a: added){
                if(visited[a]){
                    visited[a] = 0;
                    b1.update(a, -1);
                }
                b2.update(a, -1);
            }
            if(i == j) return false;            
        }
        return true;
    };

    while(lo < hi){
        ll mid = (hi - lo) / 2 + lo;

        if(check(mid)) hi = mid;
        else lo = mid+1;
    }

    cout << hi << endl;
}