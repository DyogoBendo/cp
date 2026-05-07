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

vector<ll> fib;
map<ll, int> mp;
vector<int> curr;
int check(ll x){
    if(x == 1) return 1;
    if(mp[x]) return mp[x];
    dbg(x);
    for(int i = sz(fib) -1; i >= 0; i--){
        ll f = fib[i];
        if(x % f == 0){
            curr.push_back(i);
            if(check(x / f) == 1) return mp[x] = 1;
            curr.pop_back();
        }
    }
    return mp[x] = -1;
}

signed main(){
    darvem;
    ll n;
    cin >> n;

    int cnta = 0;

    fib.push_back(2);
    fib.push_back(3);

    while(fib.back() < n){
        int s = sz(fib);
        fib.push_back(fib[s - 1] + fib[s-2]);
    }    

    if(check(n) == -1){
        cout << "IMPOSSIBLE" << endl;
    } else{
        for(auto a : curr){
            for(int i = 0; i <= a; i++) cout << "A";
            cout << "B";
        }
        cout << endl;
    }
    return 0;
}