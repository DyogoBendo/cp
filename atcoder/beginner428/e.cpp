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
    vector<vector<int>> tree(n+1);
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<pair<int, int>> all_ans(n+1);
    vector<pair<int, int>> second_bst(n+1);
    vector<int> subtree(n+1);
    function<pair<int, int>(int, int)> dfs = [&](int curr, int p){
        pair<int, int> ans = {0, curr};        
        for(auto e : tree[curr]){
            if(e == p) continue;
            auto c = dfs(e, curr);
            c.first++;
            if(c > ans){
                second_bst[curr] = ans; 
                ans = c;
                subtree[curr] = e;
            } else if(c > second_bst[curr]){
                second_bst[curr] = c;
            }            
        }
        dbg(curr, ans.first, ans.second);
        return all_ans[curr] =  ans;
    };

    function<void(int, int, pair<int, int>)> dfs2 = [&](int curr, int p, pair<int, int> pa){        
        pa.first++;
        dbg(curr, p, pa.first, pa.second);        
        if(pa > all_ans[curr]){
            subtree[curr] = -1;
            second_bst[curr] = all_ans[curr];
            all_ans[curr] = pa;
        } else if(pa > second_bst[curr]){
            second_bst[curr] = pa;
        }

        dbg(all_ans[curr].first, all_ans[curr].second, second_bst[curr].first, second_bst[curr].second);

        for(auto e : tree[curr]){
            if(e == p) continue;
            if(subtree[curr] == e) dfs2(e, curr, second_bst[curr]);
            else dfs2(e, curr, all_ans[curr]);            
        }    
    };

    dfs(1, 1);
    dfs2(1, 1, {-1, -1});
    
    for(int i = 1; i<= n; i++) cout << all_ans[i].second << endl;    
}