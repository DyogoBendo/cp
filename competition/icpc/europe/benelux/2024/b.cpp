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

const int MAXN = 5010;
const int D = 4;
const int MAXK = 25;

signed main(){
    darvem;

    int n, k;
    cin >> n >> k;

    vector<vector<int>> g(n+1, vector<int>(4));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++) cin >> g[i+1][j];
    }

    if(n == 1){
        cout << 0 << endl;
        return 0;
    } 

    auto solve = [&](int start, int d){
        queue<tuple<int, int, int, int, int>> q; // quem, distancia, numero de blinks disponíveis, direção que veio, direção do blinker
        q.push({start, 1, k, d, 0});
        int visited[MAXN][MAXK][D][3] = {0};
        while(!q.empty()){
            auto [curr, dst, blinks, dir, db] = q.front(); q.pop();            
            db++;
            if(blinks < 0) continue;
            if(visited[curr][blinks][dir][db]) continue;
            visited[curr][blinks][dir][db] = dst;
            db--;

            for(int j = 0; j < 4; j++){
                if((2 + dir) % 4 == j) continue; // U-turn
                if(g[curr][j] == 0) continue; // nenhum lugar pra ir                
                int i;
                for(i = 0; i < 4; i++) if(g[g[curr][j]][i] == curr) break;

                if(j == dir) q.push({g[curr][j], dst+1, blinks, (i+2) % 4, 0}); // seguir na mesma direção que veio
                else{
                    int turn_direction;
                    if(dir % 2 == 0){
                        turn_direction =  (j == dir + 1) ? 1 : -1;
                    } else{
                        turn_direction =  (j == dir - 1) ? -1 : 1;
                    }
                    q.push({g[curr][j], dst+1, blinks - (turn_direction != db), (i+2) % 4, turn_direction});
                }
            }
        }        
        int ans = 1e9;
        for(int i = 0; i < MAXK; i++) for(int j = 0; j < 4; j++) for(int l = 0; l < 3; l++) if(visited[n][i][j][l]) ans = min(ans, visited[n][i][j][l]);
        return ans;
    };

    int bst = 1e9;
    for(int i = 0; i < 4; i++){
        if(g[1][i]) bst = min(bst, solve(g[1][i], i));
    }
    if(bst == 1e9) cout << "impossible" << endl;
    else cout << bst << endl;
}