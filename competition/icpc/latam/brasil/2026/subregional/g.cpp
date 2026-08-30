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

const int MAX = 1e5 + 10;
const int MAXM = 5e5 + 10;
const int INF = 1e9;
int ans[MAX];

struct Bit {
	int n;
	vector<ll> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {
        for (int i = 0; i <= n; i++) bit[i] = INF;					
    }
	void update(int i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] = min(x, bit[i]);
	}
	int pref(int i) { // soma [0, i]
		ll ret = INF;
		for (i++; i; i -= i & -i) ret = min(bit[i], ret);
		return ret;
	}	
};

namespace aho {
	map<char, int> to[MAXM];
	int link[MAXM], idx, term[MAXM], exit[MAXM], sobe[MAXM], word[MAXM], lst, tam[MAXM];

	void insert(string& s) {
		int at = 0;
        lst++;
		for (char c : s) {
			auto it = to[at].find(c);
			if (it == to[at].end()) at = to[at][c] = ++idx;
			else at = it->second;
		}
		term[at]++, sobe[at]++;
        word[at] = lst;
        tam[lst] = sz(s);        
	}
	void build() {
		queue<int> q;
		q.push(0);
		link[0] = exit[0] = -1;
		while (q.size()) {
			int i = q.front(); q.pop();
			for (auto [c, j] : to[i]) {
				int l = link[i];
				while (l != -1 and !to[l].count(c)) l = link[l];
				link[j] = l == -1 ? 0 : to[l][c];
				exit[j] = term[link[j]] ? link[j] : exit[link[j]];
				if (exit[j]+1) sobe[j] += sobe[exit[j]];
				q.push(j);
			}
		}
	}

    void add_word(int pos, int at, Bit &bit, int t){
        int w = word[at];
        int l = pos - tam[w] + 1;     
        int p = t - l;        
        bit.update(p, w);
    }
	void solve(string& s, vector<vector<pair<int, int>>> queries) {        
		int at = 0;
        Bit bit(sz(s) + 1);
		for (int pos = 0; pos < sz(s); pos++){
            char c = s[pos];
			while (at != -1 and !to[at].count(c)) at = link[at];
            at = at == -1 ? 0 : to[at][c];			

            int curr= at;
            while(curr != -1){                
                if(term[curr]) add_word(pos, curr, bit, sz(s));
                curr = exit[curr];                
            }

            for(auto q : queries[pos]){
                int bst = bit.pref(sz(s) - q.first);                   
                ans[q.second] = bst;
                if(ans[q.second] == INF) ans[q.second] = -1;
            }

		}		
	}
}

signed main(){
    darvem;

    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<string> genes(n);
    for(int i = 0; i < n; i++){
        string t;
        cin >> t;
        aho::insert(t);
    }  
    
    aho::build();    

    int q;
    cin >> q;
    vector<vector<pair<int, int>>> queries(sz(s) + 1);
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;        
        queries[b].push_back({a, i});
    }

    aho::solve(s, queries);

    for(int i = 0; i < q; i++) cout << ans[i] << endl;
}