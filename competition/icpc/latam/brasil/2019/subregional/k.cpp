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

#define int ll

const int MOD = 1e9 + 7;

int d[] = {1, 0, -1};

int calc(int n){
    vector<vector<int>> m(2, vector<int>(n));
    
    for(int i = 0; i < n; i++) m[0][i] = i;
    for(int i = 0; i < n; i++) m[1][i] = i+n;
    
    vector<vector<int>> g(2*n);

    for(int i = 0; i < n; i++){
        for(int x = 0; x < 3; x++) for(int y = 0; y < 3; y++){
            int dx = d[x];
            int dy = d[y];
            if(dx == 0 and dy == 0) continue;

            int gx = i + dx;
            int gy = 0 + dy;

            if(gx < 0 or gx >= n) continue;
            if(gy < 0 or gy > 1) continue;

            g[i].push_back(m[gy][gx]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int x = 0; x < 3; x++) for(int y = 0; y < 3; y++){
            int dx = d[x];
            int dy = d[y];
            if(dx == 0 and dy == 0) continue;

            int gx = i + dx;
            int gy = 1 + dy;

            if(gx < 0 or gx >= n) continue;
            if(gy < 0 or gy > 1) continue;            

            g[i+n].push_back(m[gy][gx]);
        }
    }

    vector<int> visited(2*n);
    int cnt = 0;
    function<void(int, int)> dfs = [&](int curr, int depth){
        if(visited[curr]) return;        
        visited[curr] = 1;
        if(depth == 2*n) cnt++;                    
        for(auto e : g[curr]) dfs(e, depth+1);
        visited[curr] = 0;
    };

    int cnt2 = 0;
    dfs(0, 1);
    int cnt3 = cnt;

    cnt = 0;

    dbg(n);
    for(int i = 0; i < 2*n; i++){
        dfs(i, 1);
        cnt2 += cnt;
        //dbg(i, cnt);
        cnt = 0;
    }
    dbg(n, cnt3, cnt2);
    return cnt;
}

int fast_expo(int x, int k){
    int ans = 1;
    while(k){
        if(k & 1){
            ans = (ans * x) % MOD;
        }
        x = (x * x) % MOD;
        k >>= 1;
    }
    return ans;
}

vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b){
    vector<vector<int>> tmp(2, vector<int>(2));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++) 
                tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j] % MOD) % MOD;            
        }
    }
    return tmp;
}

int fast_expo_fibo(int k){
    vector<vector<int>> ans = {{1, 0}, {0, 1}};    
    vector<vector<int>> fib_base = {{0, 1}, {1, 1}};        
    while(k){
        if(k & 1) ans = mul(ans, fib_base);        
        fib_base = mul(fib_base, fib_base);
        k >>= 1;
    }
    return ans[1][0];
}

signed main(){
    darvem;

    int n;
    cin >> n;

    if(n == 1){
        cout << 2 << endl;
        return 0;
    }

    int f = fast_expo_fibo(n+1);
    int b = ((8 * f) % MOD - (2*n) % MOD - 6 + MOD) % MOD;
    int p = fast_expo(2, n);

    dbg(f, b, p);

    cout << (p * b) % MOD << endl;
}