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
string trash, line;

const int MAXN = 23;

int is_p[MAXN][MAXN][MAXN];
tuple<int, int, int> a_list[MAXN*MAXN*MAXN], b_list[MAXN*MAXN*MAXN], c_list[MAXN*MAXN*MAXN];
int a_cnt, b_cnt, c_cnt, px, py, pz, cnt_visited_b, cnt_visited_c;

int b_value[6*MAXN*MAXN*MAXN];
int c_value[6*MAXN*MAXN*MAXN];

int visited_b[MAXN*MAXN*MAXN];
int visited_c[MAXN*MAXN*MAXN];

signed main(){
    darvem;

    int n;
    cin >> n;

    for(int z = 0; z < n; z++){
        cin >> trash;
        for(int y = 0; y < n; y++){
            cin >> line;
            for(int x = 0; x < n; x++){
                char ch = line[x];

                if(ch == 'B') b_list[b_cnt++] = {x, y, z};
                else if(ch == 'A') a_list[a_cnt++] = {x, y, z};
                else if(ch == 'P') is_p[x][y][z] = 1;
                else c_list[c_cnt++] = {x, y, z};
            }
        }
    }

    ll ans = 0;    
    for(int x = -n; x < n; x++){
        for(int y = -n; y < n; y++){
            for(int z = -n; z < n; z++){                
                bool possible = false;

                for(int i = 0; i < a_cnt; i++){
                    auto [ax, ay, az] = a_list[i];
                    px = x + ax;
                    py = y + ay;
                    pz = z + az;                    

                    if(px >= 0 and py >= 0 and pz >= 0 and px < n and py < n and pz < n and is_p[px][py][pz]){
                        possible = true;
                        break;
                    }
                }
                if(!possible) continue;;

                dbg(x, y, z);
                
                cnt_visited_b = 0;
                for(int i = 0; i < b_cnt; i++){
                    auto [bx, by, bz] = b_list[i];
                    int dot_product = (x*bx + y*by + z*bz) +(3*MAXN*MAXN);
                    if(!b_value[dot_product]){
                        visited_b[cnt_visited_b] = dot_product;
                        cnt_visited_b++;
                    }
                    b_value[dot_product]++;
                }

                cnt_visited_c = 0;
                for(int i = 0; i < c_cnt; i++){
                    auto [cx, cy, cz] = c_list[i];
                    int dot_product = (x*cx + y*cy + z*cz) +(3*MAXN*MAXN);
                    if(!c_value[dot_product]){
                        visited_c[cnt_visited_c] = dot_product;
                        cnt_visited_c++;
                    }
                    c_value[dot_product]++;
                }

                 for(int i = 0; i < a_cnt; i++){
                    auto [ax, ay, az] = a_list[i];
                    px = x + ax;
                    py = y + ay;
                    pz = z + az;

                    if(px >= 0 and py >= 0 and pz >= 0 and px < n and py < n and pz < n and is_p[px][py][pz]){                        
                        int dota = (x*ax + y*ay + z*az) +(3*MAXN*MAXN);
                        int dotp = (x*px + y*py + z*pz) +(3*MAXN*MAXN);

                        dbg(ax, ay, az, px, py, pz, dota, dotp, b_value[dota], c_value[dotp]);

                        ans += 1LL* b_value[dota] * c_value[dotp];
                    }
                }

                for(int i = 0; i < cnt_visited_b; i++) b_value[visited_b[i]] = 0;
                cnt_visited_b = 0;

                for(int i = 0; i < cnt_visited_c; i++) c_value[visited_c[i]] = 0;
                cnt_visited_c = 0;        
            }
        }
    }
    cout << ans << endl;
}