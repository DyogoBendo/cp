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

const int MOD = 1e9 + 7;
vector<int> primes;
const int MAXN = 5e5 + 100;
int marked[MAXN];

void crivo(){
    for(int i = 2; i < MAXN; i++){
        if(!marked[i]){
            primes.push_back(i);
            for(int j = i; j < MAXN; j += i) marked[j] = i;
        }
    }
}

void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> v(n);


    map<int, ll> mp;
    for(int i = 0; i < n; i++){
        int y;
        cin >> y;

        while(y > 1){
            mp[marked[y]] ++;
            y = y / marked[y];
        }
    }

    ll ans = 1;
    for(auto [a, b] : mp){

        ans = (ans * (b + 1) ) % MOD;
    }
    cout << ans << endl;
}


signed main(){
    crivo();
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}