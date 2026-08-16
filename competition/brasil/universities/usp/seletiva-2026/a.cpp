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

const int MAX = 1e5 + 67;
const int MOD = 1e9 + 7;
int n;

namespace aho {
	map<char, int> to[MAX];
    int idx_to_id[MAX];

	int link[MAX], idx, term[MAX], exit[MAX], sobe[MAX];

	void insert(string& s, int id) {
		int at = 0;
		for (char c : s) {
			auto it = to[at].find(c);
			if (it == to[at].end()) at = to[at][c] = ++idx;
			else at = it->second;
		}     
        idx_to_id[at] = id;   
		term[at]++, sobe[at]++;        
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
	vector<int> query(string& s) {
        vector<int> v;
		int at = 0;
		for (char c : s){
            while (at != -1 and !to[at].count(c)) at = link[at];
			at = at == -1 ? 0 : to[at][c];			

            if(term[at]) v.push_back(idx_to_id[at]);            
            int curr = exit[at];            
            while(curr != -1){                
                v.push_back(idx_to_id[curr]);
                curr = exit[curr];
            }
		}
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());        

		return v;
	}
}

signed main(){
    darvem;
    
    cin >> n;

    vector<tuple<int, string, int>> entries;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        aho::insert(s, i);
        entries.push_back({sz(s), s, i});
    }

    aho::build();

    sort(entries.begin(), entries.end());

    vector<int> dp(n), can(n, 1);
    int ans = 0;
    for(auto [tam, s, i] : entries){                
        dp[i] = 1;        
        for(int j : aho::query(s)) if(j != i){            
            dp[i] = (dp[i] + dp[j]) % MOD;
            can[j] = 0;
        }                        
    }

    for(int i = 0; i < n; i++) if(can[i]) ans = (ans + dp[i]) % MOD;

    cout << ans << endl;
}