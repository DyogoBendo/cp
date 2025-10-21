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
    int n;
    cin >> n;

    vector<vector<int>> tree(n+1);

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> parent(n+1);
    vector<int> depth(n+1);
    vector<int> conn(n+1);

    vector<vector<int>> to_remove(2);

    function<void(int, int, int)> dfs = [&](int curr, int p, int d){
        conn[curr]++;
        parent[curr] = p;
        depth[curr] = d;
        bool leaf = true;
        for(auto e : tree[curr]) if(e != p){
            conn[curr]++;
            dfs(e, curr, d ^ 1);
            leaf = false;
        }
        if(leaf){        
            to_remove[d].push_back(curr);
        } 
    };

    dfs(n, n, 0);

    int curr = depth[1] ^ 1;    
    vector<string> ans;
    while(!to_remove[0].empty() or !to_remove[1].empty()){        
        if(to_remove[curr].empty()){
            ans.push_back("1");            
            curr ^= 1;
            continue;
        }
        int x = to_remove[curr].back();
        to_remove[curr].pop_back();
        ans.push_back("2 " + to_string(x));
        ans.push_back("1");            

        int p = parent[x];        
        conn[p]--;
        curr ^=1;
        if(p != n and conn[p] == 1) to_remove[curr].push_back(p);
    }


    cout << sz(ans) << endl;
    for(auto a : ans) cout << a << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}