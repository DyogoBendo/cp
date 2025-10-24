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
const int MAX = 2e5+10;
int v[MAX];

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) cin >> v[i+1];    

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
    
    vector<ll> dp(n+2);
    vector<int> ran(n+2, -1);

    for(auto [x, op, idx] : entries){                
        if(removed[idx] or op == 0) continue;        
        ran[x+1] = a[idx];
    }    

    int cur = -1;
    vector<pair<ll, int>> hp;
    for(int i = 1; i <= n+1; i++){
        cur = max(ran[i], cur);        
        if(cur == -1)dp[i] = v[i];
        else{
            while(hp.front().second < cur){                
                pop_heap(hp.begin(), hp.end());
                hp.pop_back();
            }              
            dp[i] = -hp.front().first + v[i];
        }        
        hp.push_back({-dp[i], i});
        push_heap(hp.begin(), hp.end());
    }

    cout << dp[n+1] << endl;
}