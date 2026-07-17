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

const int mx = 3e5+123;
vector<int> g [mx], comp(mx), low(mx), num(mx), vis(mx);
stack<int> vert;
int ti=0, ncomp=0;

void tarzan(int u){
    low[u] = num[u] = ++ti;
    vis[u] = 2;
    vert.push(u);
    for (auto v: g[u]){
        if (!vis[v]){
            tarzan(v);
            low[u] = min(low[u], low[v]);
        }
        if (vis[v] == 2) low[u] = min(low[u], low[v]);
    }

    if (num[u] == low[u]){
        ncomp++;
        while (!vert.empty()){
            int v = vert.top(); vert.pop();
            comp[v] = ncomp;
            vis[v] = 1;
            if (u == v) break;
        }
    }
}
map<string, int> idx, seen;

void solution(){
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    int names=0;
    for (int i=0; i<n; i++){
        string a="", b="";
        getline(cin, s);
        for (auto c: s){
            if (c == ',') break;
            a += c;
        }
        reverse(all(s));
        for (auto c: s){
            if (c == ' ') break;
            b += c;
        }
        reverse(all(b));

        if (!seen[a]) idx[a] = n+names++, seen[a] = 1;
        if (!seen[b]) idx[b] = n+names++, seen[b] = 1;
        dbg(a, idx[a]);
        dbg(b, idx[b]);
        g[idx[b]].push_back(i);
        g[i].push_back(idx[a]);
    }

    for (int i=0; i<n+names; i++){
        if (!vis[i]) tarzan(i);
        dbg(i, comp[i]);
    }

    vector<set<int>> inn (ncomp+1);
    for (int i=0; i<n+names; i++){
        dbg(i, comp[i]);
        for (auto j: g[i]){
            dbg(j, comp[j]);
            if (comp[j] != comp[i]) inn[comp[j]].insert(comp[i]);
        }
    }
    int cnt=0;
    for (int i=1; i<=ncomp; i++){
        if (inn[i].size() == 0) cnt++;
    }
    cout << (cnt==1? "possible" : "impossible") << '\n';
}

signed main(){
    fastio;
    int cases = 1;

    for (int i = 0; i < cases; i++)
    {
        solution();
    }
    
}