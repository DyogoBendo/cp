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

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int interaction(int a, int b){
    cout << a << " " << b << endl;
    int x;
    cin >> x;
    return x;
}

void solve(){
    int n;
    cin >> n;

    bool found = false;
    for(int i = 0; !found; i++){
        for(int j = 1; j <= n and !found; j++){
            found = interaction(j, (j + i) % n + 1);
        }    
    }

}


signed main(){    
    int t = 1;
    cin >> t;

    while(t--) solve();
}