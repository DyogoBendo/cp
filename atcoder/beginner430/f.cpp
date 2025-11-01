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
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> g(n), gi(n);
    vector<int> in(n), ini(n);
    for(int i = 0; i < n -1; i++){
        if(s[i] == 'R'){
            g[i].push_back(i+1);
            in[i+1]++;

            gi[i+1].push_back(i);
            ini[i]++;
        } else{
            g[i+1].push_back(i);
            in[i]++;

            gi[i].push_back(i+1);
            ini[i+1]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < n; i++) if(in[i] == 0) q.push(i);

    vector<int> prev(n);
    while(!q.empty()){
        int curr = q.front(); q.pop();
        for(auto e : g[curr]){
            prev[e] += prev[curr] + 1;
            in[e] --;
            if(in[e] == 0) q.push(e);
        }
    }   

    vector<int> after(n);
    for(int i = 0; i < n; i++) if(ini[i] == 0) q.push(i);
    while(!q.empty()){
        int curr = q.front(); q.pop();
        for(auto e : gi[curr]){
            after[e] += after[curr] + 1;
            ini[e] --;
            if(ini[e] == 0) q.push(e);
        }
    }

    vector<int> ans(n+1);

    for(int i = 0; i < n; i++){        
        ans[prev[i]]++;
        ans[n - after[i]]--;
    }

    int tot = 0;
    for(int i = 0; i < n; i++){
        tot += ans[i];
        cout << tot << " ";
    }     
    cout << endl;
}   


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}