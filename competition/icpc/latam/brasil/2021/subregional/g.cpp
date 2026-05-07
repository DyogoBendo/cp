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

int get_p2(ll x){
    if(__builtin_popcountll(x) > 1) return -1;
    return 64 - __builtin_clzll(x);
}

signed main(){
    darvem;
    ll n;
    cin >> n;

    int cnta = 0;

    vector<ll> fib;
    fib.push_back(2);
    fib.push_back(3);

    while(fib.back() < n){
        int s = sz(fib);
        fib.push_back(fib[s - 1] + fib[s-2]);
    }    

    vector<int> candidates;
    for(auto x : fib){
        if(n % x == 0) candidates.push_back(x);
    }

    cout << sz(fib) << endl;

    return 0;
}