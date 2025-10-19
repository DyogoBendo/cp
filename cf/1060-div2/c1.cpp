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

const int MAXX=2e5 + 10;

vector<int> primes;

void init(){
    vector<int> visited(MAXX);
    primes.push_back(2);
    for(int i = 2; i * i <= MAXX; i+=2) visited[i] = 1;
    for(int i = 3;i*i <= MAXX; i+= 2){
        if(!visited[i]){            
            primes.push_back(i);
            for(int j = i; j * j <= MAXX; j += i) visited[j] = 1;
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n), v2(n);
    vector<int> b(n);
    
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    for(int i = 0; i < n; i++) v2[i] = v[i]+1;

    map<int, int> ok, prox;
    set<int> extra;
            
    for(auto x : v){
        int px = x;
        for(auto p : primes){                        
            if(px == 1) break;
            if(x % p== 0) ok[p] ++;                        
            while(px % p== 0) px/=p;                        
        }                
        if(px > 1){
            ok[px]++;            
            extra.insert(px);
        } 
    }

    for(auto x : v2){
        int px = x;
        for(auto p : primes){                        
            if(px == 1) break;
            if(x % p== 0) prox[p] ++;                        
            while(px % p== 0) px/=p;                        
        }                
        if(px > 1) prox[px]++;            
    }
    
    
    int bst = 2;
    for(int p : primes){
        if(ok[p] >= 2) bst = 0;
        else if(ok[p] == 1 and prox[p] >= 1) bst =min(bst, 1);        
    }
    for(int p :extra){
        if(ok[p] >= 2) bst = 0;
        else if(ok[p] == 1 and prox[p] >= 1) bst =min(bst, 1);        
    }

    cout << bst << endl;
}


signed main(){
    init();
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}