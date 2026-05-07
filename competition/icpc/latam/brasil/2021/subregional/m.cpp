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

    int q;
    cin >> q;

    vector<vector<int>> g(1);    
    vector<int> dead(1);

    stack<pair<int, int>> st;
    st.push({0, 0});    
    auto dfs = [&](){
        while(!st.empty()){
            auto [curr, nxt_child] = st.top();            
            if(dead[curr]){
                st.pop();
                if(nxt_child < sz(g[curr]) - 1){
                    st.push({curr, nxt_child + 1});
                }
                if(nxt_child < sz(g[curr])) st.push({g[curr][nxt_child], 0});
            } else return curr;
        }
        
        return 0;
    };

    int cnt = 0;    
    while(q--){
        int t, x;
        cin >> t >> x;

        x--;
        if(t == 1){
            cnt++;
            g[x].push_back(cnt);
            g.push_back(vector<int>());
            dead.push_back(0);
        } else{
            dead[x] = 1;
            cout << dfs()+1 << endl;
        }
    }
}