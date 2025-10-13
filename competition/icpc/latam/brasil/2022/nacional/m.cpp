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

typedef bitset<100> bs;

int r, c;
vector<bs> get_rotations(string &s){
    vector<bs> rotations;
    for(int i = 0; i < c; i++){
        rotations.push_back(bs(s));
        rotate(s.begin(), s.begin() + 1, s.end());
    }
    return rotations;
}

int comp(bs &a, bs &b){
    return (a & b).none();    
}

signed main(){
    darvem;
    string s;
    cin >> r >> c >> s;

    vector<bs> rb = get_rotations(s);
    reverse(s.begin(), s.end());
    vector<bs> re = get_rotations(s);        

    vector<bs> grid(r);
    for(int i = 0; i < r; i++){
        cin >> s;
        grid[i] = bs(s);
    }

    auto solve = [&](vector<bs> nut){
        vector<vector<int>> visited(r, vector<int>(c));
        function<int(int, int)> dfs = [&](int row, int rotation){
            if(row == r) return 1;
            if(row < 0) return 0;
            if(visited[row][rotation]) return 0;
            visited[row][rotation] = 1;            
            if(!comp(grid[row], nut[rotation])) return 0;

            return max({
                dfs(row-1, rotation),
                dfs(row+1, rotation),
                dfs(row, (rotation-1 + c) % c),
                dfs(row, (rotation+1) % c)
            });
        };
        int ans = 0;
        for(int i = 0; i < c; i++) ans |= dfs(0, i);
        return ans;
    };

    int ans = max(solve(rb), solve(re));
    
    cout << (ans? "Y" : "N") << endl;
}