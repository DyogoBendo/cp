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

const int MAX2 = 20;
const int MAX = 2e5+10;

namespace sparse {
	int m[MAX2][MAX], n;
	void build(int n2, int* v) {
		n = n2;
		for (int i = 0; i < n; i++) m[0][i] = v[i];
		for (int j = 1; (1<<j) <= n; j++) for (int i = 0; i+(1<<j) <= n; i++)
			m[j][i] = min(m[j-1][i], m[j-1][i+(1<<(j-1))]);
	}
	int query(int a, int b) {
		int j = __builtin_clz(1) - __builtin_clz(b-a+1);
		return min(m[j][a], m[j][b-(1<<j)+1]);
	}
}

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    int v[MAX];
    for(int i = 0; i < n; i++) cin >> v[i];
    sparse::build(n, v);

    vector<tuple<int, int, int>> entries;    
    vector<int> a(m);
    vector<int> b(m);
    map<int, pair<int, int>> repeateds, repeatede;
    vector<int> removed(m);
    for(int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;
        
        if(repeateds[s].first){
            if(repeateds[s].first > e){                
                removed[repeateds[s].second] = 1;                
                repeateds[s] = {e, i};
            } else continue;            
        } else repeateds[s] = {e, i};

        if(repeatede[e].first){
            if(repeatede[e].first < s){                
                removed[repeatede[e].second] = 1;                
                repeatede[e] = {s, i};
            } else continue;            
        } else repeatede[e] = {s, i};

        s--; e--;        
        entries.push_back({s, 0, i});
        entries.push_back({e, 1, i});
        a[i] = s;
        b[i] = e;
    }

    sort(entries.begin(), entries.end());

    vector<int> curr;
    int pos = 0;
    for(auto [x, op, idx] : entries){        
        if(removed[idx]) continue;
        if(op == 0) curr.push_back(idx);
        else{                     
            bool found = false;
            for(; pos < sz(curr) && !found ; pos++){                
                if(curr[pos] != idx) removed[curr[pos]] = true;
                if(curr[pos] == idx) found= true;
            }
        }
    }

    curr.clear();
    ll ans = 0;
    for(auto [x, op, idx] : entries){                
        if(removed[idx]) continue;
        if(op == 0) curr.push_back(idx);
        else{   
            if(sz(curr) == 0) continue;
            int fidx=  curr.front();
            int lidx = curr.back();            
            removed[fidx] = 1;
            
            int bst = sparse::query(a[lidx], b[fidx]);            
            for(int i = 1; i < sz(curr); i++){
                int pidx = curr[i];
                removed[pidx] = 1;                
                bst = min(bst, sparse::query(a[curr[i-1]], a[pidx]-1) + sparse::query(a[lidx], b[pidx]));                
            }            
            ans += bst;
            curr.clear();
        }
    }
    cout << ans << endl;

}