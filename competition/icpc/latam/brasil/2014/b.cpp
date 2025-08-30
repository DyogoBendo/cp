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

    int n;
    cin >> n;

    vector<int> go(n+1);
    for(int i = 1; i <= n; i++){
        if(i <= n/2){
            go[i] =i*2;
        } else{            
            go[i] =  2*i - n - 1;
        }
    }

    vector<int> visited(n+1);
    int ans = 0;
    function<void(int, int)> dfs = [&](int c, int d){
        if(visited[c]) return;     
        visited[c] = 1;
        ans = max(ans, d);
        dfs(go[c], d+1);
    };

    dfs(1, 1);

    cout << ans << endl;
}