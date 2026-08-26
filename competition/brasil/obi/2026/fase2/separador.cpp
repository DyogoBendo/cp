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
    
    int n, f;
    cin >> n >> f;

    vector<vector<int>> ans(f);

    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < f; i++) pq.push({0, -i});

    for(int i = 0; i < n; i++){
        int p;
        cin >> p;

        auto [w, pos] = pq.top(); pq.pop();
        pos = -pos;
        w = -w;

        ans[pos].push_back(p);

        w += p;

        pq.push({-w, -pos});
    }

    for(int i = 0; i < f; i++){
        for(int j = 0; j < sz(ans[i]); j++){
            cout << ans[i][j];
            if(j < sz(ans[i]) - 1) cout << " ";
        }         
        cout << endl;
    } 
}