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

    int h, w;
    cin >> h >> w;
    int ans = 0;

    vector<vector<char>> grid(h+1, vector<char>(w+1));
    for(int i = 1; i <= h; i++){
        string s;
        cin >> s;
        for(int j = 1; j<= w; j++) grid[i][j] = s[j-1];
    }

    for(int h1 = 1; h1 <= h; h1++){
        for(int h2 = h1; h2 <= h; h2++){
            for(int w1 = 1; w1 <= w; w1++){
                for(int w2 = w1; w2 <= w; w2++){
                    bool can = true;
                    for(int i = h1; i <= h2; i++){
                        for(int j = w1; j <= w2; j++){
                            if(grid[i][j] != grid[h1 + h2 - i][w1+w2-j]) can = false;
                        }
                    }
                    ans += can;
                }
            }
        }
    }

    cout << ans << endl;
}