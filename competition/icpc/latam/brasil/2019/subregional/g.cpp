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

const int N = 101;
ld m[N][N];

template<typename T> struct hungarian{
    int n;    
    vector<T> u, v;
    vector<int> p, way;
    T inf;

    hungarian(int n_) : n(n_), u(n+1), v(n+1), p(n+1), way(n+1){        
        inf = numeric_limits<T>::max();
    }

    pair<T, vector<int>> assignment(){
        for(int i = 1; i <= n; i++){
            p[0] = i;
            int j0 = 0;
            vector<T> minv(n+1, inf);
            vector<int> used(n+1, 0);

            do
            {
                used[j0] = true;
                int i0 = p[j0], j1 = -1;
                T delta = inf;

                for(int j = 1; j <= n; j++) if(!used[j]){
                    T cur = m[i0-1][j-1] - u[i0] - v[j];
                    if(cur < minv[j]) minv[j] = cur, way[j] = j0;
                    if(minv[j] < delta) delta = minv[j], j1 = j;
                }

                for(int j = 0; j<= n; j++)
                    if(used[j]) u[p[j]] += delta, v[j] -= delta;
                    else minv[j] -= delta;
                j0 = j1;

            } while (p[j0] != 0);
            do
            {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0);                        
        }
        vector<int> ans(n);
        for(int j = 1; j <= n; j++) ans[p[j] - 1] = j-1;
        return make_pair(-v[0], ans);
    }
};

signed main(){
    darvem;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) for(int j= 0; j < n; j++){
        cin >> m[i][j];
        m[i][j] = -log(m[i][j]);
    } 

    hungarian<ld> hung(n);

    vector<int> ansh = hung.assignment().second;    
    vector<int> ans(n);
    for(int i = 0; i < n; i++) ans[ansh[i]] = i;

    for(int i = 0; i < n; i++) cout << ans[i]+1 << " "[i == n-1];
    cout << endl;
}