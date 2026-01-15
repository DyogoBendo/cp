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

const int MAXN = 1e3+10;
 
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

signed main(){
    darvem;
    init();

    int n, x;
    cin >> n;

    set<int> s;
    for(int i = 0; i < n; i++){
        cin >> x;

        int curr = 1;
        for(auto p : primes){
            if(p > x) break;

            if(x % p == 0) curr *= p;
            while(x % p == 0) x /= p;
        }
        curr *= x;
        s.insert(curr);
    }

    cout << sz(s) << endl;
}