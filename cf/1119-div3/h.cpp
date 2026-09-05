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

const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];
    
    vector<int> psum(n+1);

    for(int i = 0; i < n; i++){
        if(v[i] == -1 or v[i] == 0) continue;
        int l = max(i - v[i] + 1, 0);
        int r = min(n, v[i] + i); 
                
        psum[l] += 1;
        psum[r] += -1;
    }

    for(int i = 1; i < n; i++) psum[i] += psum[i-1];
    
    vector<int> t(n);
    for(int i = 0; i < n; i++) if(psum[i] == 0) t[i] = 1;


    int lst_l = -1;
    vector<int> dist(n);
    for(int i = 0; i < n; i++){
        if(t[i] == 1) lst_l = i;        
        int d = lst_l == -1 ? 1e9 : i - lst_l;
        dist[i] = d;
    }    

    lst_l = -1;
    for(int i = n-1; i >= 0; i--){
        if(t[i] == 1) lst_l = i;
        int d = lst_l == -1 ? 1e9 : lst_l - i;        
        dist[i] = min(d, dist[i]);
    }

    for(int i = 0; i < n; i++){
        if(v[i] == -1) continue;
        if(dist[i] != v[i]){            
            cout << 0 << endl;
            return;
        }
    }

    vector<int> has_unique(n);
    set<int> related;

    vector<vector<int>> g(n);

    for(int i = 0; i < n; i++){
        if(v[i] == -1) continue;
        int l = -1, r = -1;     

        int ml = i - v[i];
        int mr = i + v[i];
        if(ml >= 0 and t[ml]) l = ml;
        if(mr < n and t[mr]) r = mr;

        if(l == -1) has_unique[r] = 1;
        else if(r == -1) has_unique[l] = 1;        
    }

    for(int i = 0; i < n; i++){
        if(v[i] == -1) continue;
        int l = -1, r = -1;     

        int ml = i - v[i];
        int mr = i + v[i];
        if(ml >= 0 and t[ml]) l = ml;
        if(mr < n and t[mr]) r = mr;


        if(l != -1 and r != -1 and 
            v[l] == -1 and v[r] == -1 
            and !has_unique[l] and !has_unique[r]) related.insert(l), related.insert(r), g[l].push_back(r), g[r].push_back(l);
    }

    vector<int> to_remove;
    for(auto x : related) if(has_unique[x]) to_remove.push_back(x);
    for(auto x : to_remove) related.erase(x);

    int cnt_used = 0;
    int ans = 1;
        
    if(sz(related)){
        cnt_used = 1;

        vector<int> visited(n);
        function<int(int)> dfs = [&](int curr){
            if(visited[curr]) return 0;
            visited[curr] = 1;
            int cnt = 1;
            for(auto e : g[curr]) cnt += dfs(e);
            return cnt;
        };

        for(int i = 0; i < n; i++){
            if(!visited[i] and sz(g[i])){
                int tot = dfs(i);
                int a = 1;
                int b = 1;
                int c = 1;
                while(tot--){
                    c = (a+b) % MOD;
                    a = b;
                    b = c;
                }
                ans = (1LL * ans * c) % MOD;
            }
        }

    }
    else ans = 1;

    for(int i = 0; i < n; i++){
        if(!t[i]) continue;

        if(v[i] == 0) cnt_used++;
        else if(has_unique[i]) cnt_used++;
        else if(!related.count(i)) ans = (ans * 2) % MOD;
    }    

    if(cnt_used == 0) ans--;

    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}