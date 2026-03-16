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

const int MAX = 4000;

int visited[MAX]; 
vector<int> primes;

void init(){
    for(int i = 2; i < MAX; i++){
        if(!visited[i]) {
            primes.push_back(i);
            for(int j = i; j < MAX; j+= i) visited[j] = 1;
        }
    }
}

void solve(){
    ll n;
    cin >> n;

    vector<int> div;
    for(int p : primes){
        if(n % p == 0){            
            div.push_back(p);
        }
    }
    
    if(sz(div) > 1){
        if(div[0] * div[1] < MAX){
            cout << 0 << endl;
            return;
        }
    }
    
    for(auto d : div){        
        int cnt= 0;        
        while(n % d == 0) n /= d, cnt++;        
        if(cnt > 1 and d*d < MAX){
            cout << 0 << endl;
            return;
        }
    }
    cout << (n > 1 ? 0 : 1) << endl;
}


signed main(){
    darvem;
    init();
    int t = 1;
    cin >> t;

    while(t--) solve();
}