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

int t = 1;

ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

vector<int> pi(string s) {
	vector<int> p(s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}

void solve(){    
    int n;
    string s;
    cin >> n >> s;
    vector<int> p(n+1), p2(n+1);    

    for(int i = 1; i <= n; i++){
        cin >> p[i];
        p2[p[i]] = i;
    } 
    
    vector<int> visited(n + 1);
    
    string sc;
    function<void(int, int)> dfs = [&](int curr, int idx){
        if(visited[curr]) return;
        visited[curr] = 1;        
        sc += s[curr-1];         

        dfs(idx, p2[idx]);
    };
    ll ans = 1;
    for(int i = 1; i <= n; i++){
        if(!visited[p[i]]){                   
            sc = "";
            dfs(p[i], i);                        
            int k = sz(sc) - pi(sc).back();
        
            int tam = k and sz(sc) % k == 0 ? k : sz(sc);
            dbg(sc, k, tam);
            ans = lcm(ans, tam);
        }
    }
    cout << ans << endl;
}


signed main(){
    darvem;
    cin >> t;

    while(t--) solve();
}