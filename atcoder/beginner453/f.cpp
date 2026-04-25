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

void solve(){
    int n, k;
    cin >> n >> k;

    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> v(k);
    for(int i = 0; i < k; i++) cin >> v[i];

    if(n == 2){        
        for(int i = 0; i < k; i++) if(v[i] >= 2){
            cout << i+1 << ' ' << i + 1 << endl;
            return;
        }
        cout << -1 << endl;
        return;
    }

    int l = 0;
    for(int i = 0; i < n; i++) l += sz(g[i]) == 1;

    dbg(l);
    bool found = false;
    int x;    

    function<int(int, int)> dfs = [&](int curr, int p){
        int s = sz(g[curr]) == 1;
        vector<int> leaves;
        for(auto e : g[curr]) if(e != p){
            int cnt = dfs(e, curr);
            s += cnt;
            leaves.push_back(cnt);
        } 
        if(!found and sz(g[curr]) > 1 and s >= (l+1)/2){            
            found = true;
            x = curr;
        }
        return s;
    };

    dfs(0, 0);

    vector<vector<int>> groups(sz(g[x]));

    function<void(int, int, int)> dfs2 = [&](int curr, int p, int c){        
        if(sz(g[curr]) == 1) groups[c].push_back(curr);        
        for(auto e : g[curr]) if(e != p) dfs2(e, curr, c);        
    };

    for(int i = 0; i < sz(g[x]); i++) dfs2(g[x][i], x, i);    

    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < sz(groups); i++) pq.push({sz(groups[i]), i});
    vector<int> colored(n);

    int colored_leaves = 0;
    for(int i = 0; i < k; i++){                
        if(v[i] >= 2 && colored_leaves < l){                    
            if(colored_leaves == l - 1){
                auto [tam, idx] = pq.top(); pq.pop();
                colored[groups[idx].back()] = i+1; groups[idx].pop_back();
                colored[x] = i+1; 
                v[i] -= 2;
                colored_leaves++;
                break; 
            }
            
            auto [tam1, idx1] = pq.top(); pq.pop();
            auto [tam2, idx2] = pq.top(); pq.pop();

            colored[groups[idx1].back()] = i+1; groups[idx1].pop_back();
            colored[groups[idx2].back()] = i+1; groups[idx2].pop_back();
            
            tam1--; tam2--;
            if(tam1) pq.push({tam1, idx1});
            if(tam2) pq.push({tam2, idx2});
            
            colored_leaves += 2;
            v[i] -= 2;
            
            while(v[i] > 0 && colored_leaves < l){
                auto [tam, idx] = pq.top(); pq.pop();
                colored[groups[idx].back()] = i+1; groups[idx].pop_back();
                
                tam--;
                if(tam) pq.push({tam, idx});
                
                colored_leaves++;
                v[i]--;
            }
        }
    }

    if(colored_leaves < l){
        cout << - 1 << endl;
        return;
    }

    int lst_colored = 0;
    for(int i = 0; i < k; i++){
        while(v[i] and lst_colored < n){
            if(colored[lst_colored]) lst_colored++;
            else colored[lst_colored++] = i+1, v[i]--;
        }
    }

    for(int i = 0; i < n; i++) cout << colored[i] << " ";
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}