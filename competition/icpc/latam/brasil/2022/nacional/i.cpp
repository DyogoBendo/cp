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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

signed main(){
    darvem;

    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c));
    
    for(int i = 0; i < r; i++) for(int j = 0; j < c; j++){
        cin >> grid[i][j];
    }

    int ans = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            bool candidate = true;
            for(int k = 0; k < 4; k++){
                int di = dx[k] + i;
                int dj = dy[k] + j;
                if(di >=0 and di < r and dj >= 0 and dj < c and grid[di][dj] < grid[i][j]){
                    candidate = false;                        
                }
            }
            if(!candidate) continue;

            priority_queue<tuple<int, int, int>> pq;            
            pq.push({-grid[i][j], i, j});
            int tot = 0;
            set<int> visited;
            while(!pq.empty()){
                auto [curr, x, y] = pq.top(); pq.pop();
                tot++;
                curr = -curr;

                for(int k = 0; k < 4; k++){
                    int di = dx[k] + x;
                    int dj = dy[k] + y;

                    if(di >=0 and di < r and dj >= 0 and dj < c and grid[di][dj] > curr && !visited.count(grid[di][dj])){
                        visited.insert(grid[di][dj]);
                        pq.push({-grid[di][dj], di, dj});
                    }
                }
            }            
            ans = max(ans, tot);
        }
    }
    cout << ans << endl;
}