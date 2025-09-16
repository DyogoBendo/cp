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
    vector<vector<int>> tree(n);

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    string s;
    cin >> s;

    int cnt_pending_leaf = 0, cnt_pending_middle = 0, cnt_one_leaf = 0, cnt_zero_leaf = 0; 
    function<void(int, int)> dfs = [&](int curr, int p){
        int cnt = 0;
        for(auto e : tree[curr]) if(e != p){
            dfs(e, curr);
            cnt++;
        }
        if(cnt == 0){
            if(s[curr] == '1') cnt_one_leaf++;
            else if(s[curr] == '0') cnt_zero_leaf++;
            else cnt_pending_leaf ++;
        } else if(curr != 0 && s[curr] == '?') cnt_pending_middle ++;
    };

    dfs(0, 0);

    int ans = 0;

    auto half = [&](int x){
        return max(x - (x/2), 0);
    };
                
    dbg(cnt_zero_leaf, cnt_one_leaf, s[0], cnt_pending_middle, cnt_pending_leaf);
    if(s[0] == '1') ans = cnt_zero_leaf + half(cnt_pending_leaf);
    else if(s[0] == '0')ans = cnt_one_leaf + half(cnt_pending_leaf);
    else{        
        ans = max(cnt_one_leaf, cnt_zero_leaf) + half(cnt_pending_leaf - 1);
        if(cnt_one_leaf == cnt_zero_leaf){
            ans = cnt_one_leaf;
            if(cnt_pending_leaf % 2 && cnt_pending_middle % 2) ans += half(cnt_pending_leaf);
            else ans += half(cnt_pending_leaf-1);
        }        
    }
    cout << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}