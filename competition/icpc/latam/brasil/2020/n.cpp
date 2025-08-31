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
const int MAX = 4e7;

static int divi[MAX];
vector<int> primes;

void crivo() {    
	divi[1] = 1;
	for (int i = 2; i < MAX; i++) {
		if (divi[i] == 0) divi[i] = i, primes.push_back(i);
		for (int j : primes) {
			if (j > divi[i] or i*j >= MAX) break;
			divi[i*j] = j;
		}
	}
}

signed main(){
    darvem;

    crivo();

    int m, n, k;
    cin >> m >> n >> k;

    vector<ll> nnodes(n);
    for(int i = 0; i < n; i++) cin >> nnodes[i];
    
    vector<vector<pair<int, int>>> g(m);

    for(int i = 0; i < k; i++){
        int a, b, c;
        cin >> a >> b >> c;

        a--;b--;        
        g[a].push_back({b, c});
    }

    vector<int> ans(m);
    int curr = 0;
    int x = nnodes[g[curr][0].first];
    for(int p : primes){        
        if(x % p == 0){
            dbg(x, p);
            ans[curr] = p;
            for(auto e : g[curr]){
                while(e.second --) nnodes[e.first] /= p;
            }
            curr++;
            if(curr < m) x = nnodes[g[curr][0].first];
            else break;
        }
    }   

    while(curr < m){
        ans[curr] =  nnodes[g[curr][0].first];
        curr++;
    }
    for(int i = 0; i < m; i++) cout << ans[i] << " ";
    cout << endl;
}