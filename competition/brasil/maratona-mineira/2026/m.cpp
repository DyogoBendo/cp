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

vector<tuple<int, int, int>> move_to_star(vector<vector<int>> &g){
    vector<tuple<int, int, int>> moves;

    set<pair<int, int>> st;

    for(int x : g[1]){
        for(int y : g[x]) if(y != 1){
            if(y < x) st.insert({y, x});
            else st.insert({-y, x});
        }   
    }

    while(!st.empty()){
        auto curr = st.begin();
        auto [a, b] = *curr;
        a = abs(a);
        dbg(a, b);
        moves.push_back({a, b, 1});

        for(int x : g[a]) if(x != b){
            if(x < a) st.insert({x, a});
            else st.insert({-x, a});
        }    
        st.erase(curr);
    }

    return moves;
}

signed main(){
    darvem;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
    }

    vector<pair<int, int>> edges_init(n-1), edges_end(n-1);
    for(auto &[a, b] : edges_init) cin >> a >> b;
    for(auto &[a, b] : edges_end) cin >> a >> b;

    vector<vector<int>> g1(n+1), g2(n+1);

    for(auto &[a, b] : edges_init) g1[a].push_back(b), g1[b].push_back(a);
    for(auto &[a, b] : edges_end) g2[a].push_back(b), g2[b].push_back(a);

    auto m1 = move_to_star(g1);
    auto m2 = move_to_star(g2);
    reverse(m2.begin(), m2.end());

    cout << sz(m1) + sz(m2) << endl;

    for(auto [a, b, c] : m1) cout << a << " " << b << " " << c << endl;
    for(auto [a, b, c] : m2) cout << a << " " << c << " " << b << endl;
}