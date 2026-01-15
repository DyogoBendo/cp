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

const int MAXN = 100;

vector<ll> primes;

void init(){
    primes.push_back(2);
    vector<int> visited(MAXN);

    for(int i = 0; i < MAXN; i+= 2) visited[i] = 1;

    for(int i = 3; i < MAXN; i+= 2){
        if(!visited[i]){
            visited[i] = 1;
            primes.push_back(i);

            for(int j = i; j < MAXN; j+= i) visited[j] = 1;
        }
    }
}

void solve(){
    ll a, b;
    cin >> a >> b;

    if(min(a, b) == 0){
        cout <<-1 << endl;
        return;
    }

    cout << a + b << endl;  
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    init();

    while(t--) solve();
}