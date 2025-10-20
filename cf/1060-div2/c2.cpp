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

#define int long long

const int MAXX=2e5 + 10;

vector<int> primes;
vector<vector<int>> factors(MAXX);

void init(){
    vector<int> visited(MAXX);
    primes.push_back(2);
    for(int i = 2; i < MAXX; i+=2){
        visited[i] = 1;
        factors[i].push_back(2);
    } 
    for(int i = 3;i < MAXX; i+= 2){
        if(!visited[i]){            
            primes.push_back(i);
            for(int j = i; j < MAXX; j += i){
                visited[j] = 1;
                factors[j].push_back(i);
            } 
        }
    }
}

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> b(n);
    
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> b[i];    

    map<int, int> cnt;
    vector<int> ap;
            
    for(auto x : v){
        for(auto f : factors[x]){            
            if(cnt[f]){
                cout << 0 << endl;
                return;
            }
            cnt[f]++;
            ap.push_back(f);
        }
    }

    ll ans = 1e18;
    for(int i = 0; i < n; i++){
        for(auto p : ap){        
            int x = v[i];
            int y = b[i];
            if(x %p == 0) continue;
            int k = p - (x%p);   
                     
            ans = min(ans, k * y);
        }
    }
    sort(b.begin(), b.end());
    ans = min(ans, b[0] + b[1]);
    
    cout << ans << endl;
}


signed main(){
    init();
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}