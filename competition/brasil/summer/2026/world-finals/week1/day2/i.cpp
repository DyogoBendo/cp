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

const int MAXN = 1986 + 1;
vector<int> primes;

void init(){
    vector<int> visited(MAXN);

    for(int i=2; i < MAXN; i++){
        if(!visited[i]){
            primes.push_back(i);
            for(int j = i; j < MAXN; j+= i) visited[j] = 1;
        }
    }
    dbg(primes.size());
}

int query(int k){
    cout << "? " << k << endl;
    int x;
    cin >> x;
    return x;
}

void answer(int x){
    cout << "! " << x << endl;
}

void solve(){
    query(1);
    
    int ans = 1;

    vector<int> factors;
    for(auto p : primes){
        if(p * ans > 1986) break;

        if(!query(p)){
            ans *= p;
            factors.push_back(p);
        }
    }    

    for(auto f : factors){
        int curr = f;
        while(ans * curr < 1986 and !query(curr*f)) curr *= f;
        curr/= f;
        ans *= curr;
    }

    answer(ans);
}

signed main(){
    init();    
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}