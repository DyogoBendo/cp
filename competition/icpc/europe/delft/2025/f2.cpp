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

signed main(){
    darvem;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    if(n%2){
        cout << "impossible" << endl;
        return 0;
    }

    for(int i = 0; i < n; i++){
        if(g[i].size() < n/2 - 1){
            cout << "impossible" << endl;
            return 0;
        }
    }

    vector<vector<int>> g2(n);

    for(int i = 0; i < n; i++){
        vector<int> v(n);
        for(int x : g[i]) v[x] = 1;

        for(int j = 0; j < n; j++) if(j != i and !v[j]) g2[i].push_back(j);
    }

    vector<int> visited(n);

    bool can = true;
    function<void(int, int, int)> dfs = [&](int curr, int color, int base){        
        if(visited[curr]){
            if(visited[curr] != color) can = false;
            return;
        }
        visited[curr] = color;

        int nxt = color == base ? base+1 : base;
        for(int v : g2[curr]){            
            dfs(v, nxt, base);        
        } 
    };

    int lst = 1;
    for(int i = 0; i < n; i++){
        if(!visited[i]){            
            dfs(i, lst, lst);
            lst += 2;
        }
    }

    if(!can){
        cout << "impossible" << endl;
        return 0;
    }

    vector<int> color_cnt(lst);    
    for(int i = 0; i < n; i++) color_cnt[visited[i]]++;
    
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    dp[0][0] = -1;    
    
    int cnt = 0;
    for(int i = 1; i < lst; i+=2, cnt++){                
        vector<int> dp2(n+1), dp3(n+1);
        for(int j = 0; j <= n; j++){            
            if(dp[cnt][j] and j + color_cnt[i] <= n){
                dp2[j + color_cnt[i]] = i;
            }
        }
        
        
        for(int j = 0; j <= n; j++){
            if(dp[cnt][j] and j + color_cnt[i+1] <= n){
                dp3[j + color_cnt[i+1]] = i+1;
            }
        }
        
        for(int j = 1; j <= n; j++){            
            if(dp2[j]) dp[cnt+1][j] = dp2[j];
            if(dp3[j]) dp[cnt+1][j] = dp3[j];            
            //dbg(j, cnt+1, dp[cnt+1][j]);
        }
    }
    
    if(!dp[cnt][n/2]){
        cout << "impossible" << endl;
        return 0;
    }
    
    set<int> red_team;
    int curr = n/2;
    while(cnt){        
        red_team.insert(dp[cnt][curr]);
        curr -= color_cnt[dp[cnt][curr]];
        cnt--;
    }    

    int totr = 0, totb = 0;
    
    for(int i = 0; i < n; i++){

        if(red_team.count(visited[i])){
            totr ++;
            cout << "r";
        } 
        else{
            totb ++;
            cout << "b";
        } 
        cout << endl;
    }
    
    dbg(totr, totb);
}