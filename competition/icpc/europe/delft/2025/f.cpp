#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) a.size())
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do {cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

vector<vector<int>> g;

vector<int> color, component, ans;

vector<vector<int>> nodesA, nodesB;

bool dfs(int u, int col, int comp){
    if (color[u]) return true;
    color[u] = col;
    component[u] = comp;
    bool can=true;
    for (auto v: g[u]){
        if (color[v]){
            if (color[v] == col) return false;
        }
        else can &= dfs(v, 3-col, comp);
    }
    return can;
}

void solution(){
    int n, m;
    cin >> n >> m;
    if (n > 4000 || n%2){
        cout << "impossible\n";
        return;
    }

    vector<vector<int>> mat (n, vector<int>(n, 1));
    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        mat[a][b] = 0;
        mat[b][a] = 0;
    }
    g.resize(n);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++){
        if (j != i && mat[i][j]) g[i].push_back(j);
    }

    color.resize(n);
    component.resize(n);
    int comp=0;

    bool can=true;
    for (int i=0; i<n; i++) if (!color[i]){
        can &= dfs(i, 1, comp++);
    }

    if (!can){
        cout << "impossible\n";
        return;
    }

    nodesA.resize(comp);
    nodesB.resize(comp);
    for (int i=0; i<n; i++){
        dbg(i, color[i]);
        if (color[i] == 1) nodesA[component[i]].push_back(i);
        else if (color[i] == 2) nodesB[component[i]].push_back(i);
    }

    vector<int> livres;
    vector<int> values (comp);
    int mn=0;
    for (int i=0; i<comp; i++){
        if (sz(nodesA[i])+sz(nodesB[i]) == 1){
            livres.push_back(nodesA[i][0]);
            continue;
        }

        if (nodesA[i].size() > nodesB[i].size()) swap(nodesA[i], nodesB[i]);
        mn = sz(nodesA[i]);
        values[i] = sz(nodesB[i]) - sz(nodesA[i]);
        dbg(i, values[i]);
    }

    int target = n/2+1;
    vector<int> dp (target), up (target, -1);
    dp[0] = 1;
    up[0] = -1;
    for (int i=0; i<sz(values); i++){
        if (!values[i]) continue;
        for (int j=target-1; j>=values[i]; j--){
            if (dp[j-values[i]]) dp[j] = 1, up[j] = i;
        }
    }

    ans.resize(n);
    can=false;
    for (int i=target-1; i>=0; i--){
        dbg(i, dp[i], up[i]);
        if (i+mn > n/2) continue;
        if (!dp[i]) continue;
        if (sz(livres)+mn+i < n/2) break;
        can = true;
        int needs=n/2-mn-i;
        while (needs--){
            ans[livres.back()] = 1;
            livres.pop_back();
        }
        int x = i;
        while (up[x] != -1){
            swap(nodesA[up[x]], nodesB[up[x]]);
            x -= values[up[x]];
        }
        break;
    }

    if (!can){
        cout << "impossible\n";
        return;
    }

    for (int i=0; i<comp; i++){
        if (sz(nodesA[i])+sz(nodesB[i]) == 1){
            continue;
        }

        for (auto a: nodesA[i]) ans[a] = 1;
    }

    for (int i=0; i<n; i++) cout << (ans[i]? 'r' : 'b') << '\n';
}

signed main(){
    fastio;
    int cases = 1;

    for (int i = 0; i < cases; i++)
    {
        solution();
    }
    
}