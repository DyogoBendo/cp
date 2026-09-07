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

const int MAXN = 402; 
const int MAXQ = 1e5 + 10;
int g[MAXN][MAXN], ga[MAXN][MAXN];
const int INF = 1e9 + 3;
int ans[MAXQ];
int n;

void solve( vector<tuple<int, int, int, int>> &queries, vector<pair<int, int>> &temp){        
    int curr_k = 0, curr_distinct = 0;    
    vector<int> added(n);            
    for(auto [k, a, b, idx] : queries){        
        if(k <= curr_distinct or curr_k == n){
            ans[idx] = ga[a][b];            
            continue;
        }
        
        int nxt = curr_k < n ? temp[curr_k].first : INF;
        int prev = nxt-1;
        while((curr_distinct < k or nxt == prev) and curr_k < n){
            int curr_adding = temp[curr_k].second;            
            added[curr_adding] = 1;
            if(nxt != prev) curr_distinct++;

            curr_k++;
            prev = nxt;
            nxt = curr_k < n ? temp[curr_k].first : prev-1;
            
            for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++){
                ga[i][j] = ga[j][i] = min(ga[i][j], ga[i][curr_adding] + ga[j][curr_adding]);
            }
        }                
        ans[idx] = ga[a][b];                
    }
}

signed main(){
    darvem;

    int r;
    cin >> n >> r;

    vector<pair<int, int>> temp(n);
    for(int i = 0; i < n; i++){
        cin >> temp[i].first;        
        temp[i].second = i;
    } 
    sort(temp.begin(), temp.end());

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) g[i][j]= INF;
    for(int i = 0; i < n; i++) g[i][i] = 0;
    for(int i = 0; i < r; i++){
        int x, y, d;
        cin >> x >> y >> d;
        x--; y--;
        g[x][y] = d;
        g[y][x] = d;                
    }
    vector<tuple<int, int, int, int>> hotq, coldq;

    int q;
    cin >> q;    
    for(int i = 0; i < q; i++){
        int a, b, k, t;
        cin >> a >> b >> k >> t;
        a--, b--;
        if(t == 0) coldq.push_back({k, a, b, i});
        else hotq.push_back({k, a, b, i});
    }

    sort(coldq.begin(), coldq.end());
    sort(hotq.begin(), hotq.end());

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ga[i][j] = g[i][j];
    solve(coldq, temp);

    reverse(temp.begin(), temp.end());
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) ga[i][j] = g[i][j];
    solve(hotq, temp);

    for(int i = 0; i < q; i++) cout << (ans[i] >= INF ? -1 : ans[i]) << endl;    
}