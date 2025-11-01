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

    vector<vector<int>> g(n), gr(n);
    vector<int> out(n);
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;

        for(int j = 0; j < c; j++){
            int x;
            cin >> x;
            g[i].push_back(x-1);
            gr[x-1].push_back(i);
            out[i]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++) if(out[i] == 0) q.push(i);

    vector<int> dp(n);
    int can = 0;
    while(!q.empty()){
        int curr = q.front(); q.pop();
        dp[curr] = 1;

        for(auto e : g[curr]){
            dp[curr] = max(dp[curr], 1 + dp[e]);
        }        
        for(auto e : gr[curr]){
            out[e]--;
            if(out[e] == 0) q.push(e);
        }        
        can |= dp[curr] == n;
    }

    cout << can << endl;

}