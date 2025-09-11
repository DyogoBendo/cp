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

    pair<int, int> st, en;

    vector<vector<char>> grid(n, vector<char>(m));

    char c;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> c;
            grid[i][j] = c;
            if(c == 'S') st = {i, j};
            if(c == 'T') en = {i, j};
        }
    }

    auto check = [&](int i, int j){
        if(i < 0) return false;
        if(i >= n) return false;
        if(j < 0) return false;
        if(j >= m) return false;        
        return grid[i][j] != '#';
    };

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    queue<tuple<int, int, int, int, int>> q;
    vector<vector<vector<int>>> distance(n, vector<vector<int>>(m, vector<int>(12, 1e9)));
    auto add = [&](int i, int j, int d, int lst, int tot){
        for(int k = 0; k < 4; k++){
            int pi = i + dx[k];
            int pj = j + dy[k];        
            int go = k == lst ? tot + 1 : 1; 
            if(check(pi, pj) && go <= 3 && distance[pi][pj][3*k + go-1] == 1e9){                
                distance[pi][pj][3*k + go - 1] = d+1;
                q.push({pi, pj, d + 1, k, go});
            }
        }
    };

    for(int i = 0; i < 12; i++) distance[st.first][st.second][i] = 0;

    add(st.first, st.second, 0, -1, 0);

    int ans = 1e9;
    while(!q.empty()){
        auto [i, j, d, lst, tot] = q.front(); q.pop();                
        if(i == en.first and j == en.second) ans = min(ans, d);        
        add(i, j, d, lst, tot);
    }
    if(ans == 1e9) ans = -1;

    cout << ans << endl;
}