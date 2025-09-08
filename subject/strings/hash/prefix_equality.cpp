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

mt19937 rng((ll) chrono::steady_clock::now().time_since_epoch().count());
 
ll uniform(ll r) {
	uniform_int_distribution<ll> uid(1, r);
	return uid(rng);
}
 

signed main(){
    darvem;

    int n, q;
    cin >> n;

    vector<int> a(n), b(n);

    map<int, ll> mp;
    for(int i = 0;  i < n; i++){
        cin >> a[i];
        if(!mp.count(a[i])){
            mp[a[i]] = uniform((1LL << 63));
        }
    } 
    for(int i = 0;  i < n; i++){
        cin >> b[i];    
        if(!mp.count(b[i])){
            mp[b[i]] = uniform((1LL << 63));
        }
    } 

    vector<ll> pa, pb;
    pa.push_back(0);
    pb.push_back(0);

    set<ll> sa, sb;
    for(int i = 0; i < n; i++){
        ll x = mp[a[i]];
        dbg(a[i], x);
        if(sa.count(x)){
            pa.push_back(pa.back());
            continue;
        } 
        sa.insert(x);
        pa.push_back(pa.back() ^ x);
    }

    for(int i = 0; i < n; i++){
        ll x = mp[b[i]];
        dbg(b[i], x);
        if(sb.count(x)){
            pb.push_back(pb.back());
            continue;
        } 
        sb.insert(x);
        pb.push_back(pb.back() ^ x);
    }

    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;

        cout << (pa[x] == pb[y] ? "Yes" : "No") << endl;
    }

}