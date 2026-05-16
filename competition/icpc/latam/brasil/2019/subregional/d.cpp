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

    int n, k;
    cin >> n >> k;
    vector<vector<int>> children(n+1);
    for(int i = 0; i < n-1; i++){
        int x;
        cin >> x;
        children[x].push_back(i+2);
    }

    vector<int> ans;
    function<int(int)> dfs = [&](int curr){        
        if(sz(children[curr]) == 0) return 1;
        vector<int> candidates;
        for(auto e : children[curr]) candidates.push_back(dfs(e));        
        sort(candidates.rbegin(), candidates.rend());

        for(int i = 1; i < sz(candidates); i++) ans.push_back(candidates[i]);        
        return candidates[0] + 1;        
    };

    ans.push_back(dfs(1));

    int tot = 0;
    sort(ans.rbegin(), ans.rend());
    for(int i = 0; i < k; i++) tot += ans[i];
    cout << tot << endl;
}