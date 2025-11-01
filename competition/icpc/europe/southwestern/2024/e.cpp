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

    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());
    map<int, vector<int>> mp;
    set<int> xs;
    int lst = -1;
    for(int i = 0; i < n; i++){
        mp[v[i].first].push_back(v[i].second);
        xs.insert(v[i].first);
        lst = v[i].first;
    } 

    set<pair<int, int>> chosen_points;
    vector<pair<int, int>> ans;    

    auto add = [&](int x, int y){
        if(chosen_points.count({x, y})) return;
        dbg(x, y);
        chosen_points.insert({x, y});
        ans.push_back({x, y});
    };    

    vector<int> one;
    bool reversed = false;    
    int reverse_pos = 1;        
    for(auto [x, p] : mp){         
        if(!reversed and x - 1 >= 1 and xs.count(x-1) == 0){
            add(x-1, 2);
            reversed = true;
            reverse_pos= x-1;
        }            
        if(reversed){
            add(x-1, 2);
            reverse(p.begin(), p.end());
            bool has_one = false;
            for(auto y : p){                
                if(y > 1) add(x, y);
                else one.push_back(x);                                
            } 
            if(x != lst) add(x, 2);
            else add(x, 1);

        } else{
            add(x, 2);
            for(auto y : p){
                if(y > 1) add(x, y);
                else one.push_back(x);
            } 
            add(x+1, 2);
        }             
    }
    while(!one.empty()){
        add(one.back(), 1);
        one.pop_back();
    }
    add(min(v[0].first, reverse_pos), 2);

    assert(sz(ans) <= 3*n);

    cout << sz(ans) << endl;
    for(auto [x, y] : ans) cout << x << " " << y << endl;
}