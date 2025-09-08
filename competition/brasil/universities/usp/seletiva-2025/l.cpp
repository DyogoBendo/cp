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

typedef vector<vector<int>> M;

int dx[] = {1, 0, -1};
int dy[] = {1, 0, -1};
int n;

M mul(M m1, M m2, int a, int b, int c){
    M tmp(a, vector<int>(b));    

    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            for(int k = 0; k < c; k++){                
                tmp[i][j] += m1[i][k] * m2[k][j] % 2;
                tmp[i][j] %= 2;
            }
        }
    }
    return tmp;
}

M expo(M b, ll k){
    int x = n*n;
    M ans(x, vector<int>(x));
    for(int i = 0; i < x; i++) ans[i][i] = 1;
    
    while(k){
        if(k & 1) ans = mul(ans, b, x, x, x);
        b = mul(b, b, x, x, x); 
        k >>= 1;
    }
    return ans;
}

signed main(){
    darvem;
    
    int k;
    cin >> n >> k;

    vector<string> init(n);

    for(int i = 0; i < n; i++){
        cin >> init[i];
    }

    M transition(n * n, vector<int>(n * n));

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            if(init[i][j] == '#') continue;
            int pos= (i * n) + j;
            for(int px = 0; px < 3; px++) for(int py = 0; py < 3; py++){
                int x = i + dx[px];
                int y = j + dy[py];                
                if(x < 0 or x >= n or y < 0 or y >= n) continue;
                if(init[x][y] == '#') continue;

                int p2 = (x*n) + y;
                transition[pos][p2] = 1;                 
            }
        }
    }
    
    M t = expo(transition, k);


    M v(1, vector<int>(n*n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            v[0][(i*n) + j] = init[i][j] == '1';
        }
    }    

    M ans = mul(v, t, 1, n*n, n*n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(init[i][j] == '#') cout << '#';
            else cout << ans[0][(i*n)+j];
        }
        cout << endl;
    }

}