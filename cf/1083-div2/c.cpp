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

const int MAX = 1e6 + 10;

int visited[MAX];

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> v(n);

    for(int i = 0; i < n; i++){
        int l;
        cin >> l;

        vector<int> x(l);

        for(int j = 0; j < l; j++) cin >> x[j];

        reverse(x.begin(), x.end());

        v[i] = x;
    }

    vector<int> lst_position(n);

    vector<int> alive(n, 1);
    int cnt_alive = n;
    vector<int> ans;
    while(cnt_alive){
        vector<int> curr_alive = alive;
        while(1){
            int mn = 1e7;
            vector<int> pos_min;
            for(int i = 0; i < n; i++) if(curr_alive[i]) {
                int x;
                while(lst_position[i] < sz(v[i]) and visited[v[i][lst_position[i]]]) lst_position[i]++;

                if(lst_position[i] == sz(v[i])){
                    x = -1;
                } else{
                    x = v[i][lst_position[i]];
                }

                if(x < mn){
                    mn = x;
                    pos_min.clear();
                    pos_min.push_back(i);
                } else if(x == mn){
                    pos_min.push_back(i);
                }
            }

            for(int i = 0; i < n; i++) curr_alive[i] = 0;
            for(auto p : pos_min){
                lst_position[p]++;
                if(mn != -1) curr_alive[p] = 1;
            }

            if(mn != -1){
                ans.push_back(mn);
                visited[mn] = 1;
            } 
            
            if(sz(pos_min) == 1){
                int pos = pos_min[0];
                for(int i = lst_position[pos]; i < sz(v[pos]); i++){
                    if(!visited[v[pos][i]]){
                        visited[v[pos][i]] = 1;
                        ans.push_back(v[pos][i]);
                    } 
                    lst_position[pos]++;
                }
                alive[pos] = 0;
                cnt_alive--;
                break;
            }
            
            if(mn == -1){
                for(auto p : pos_min) curr_alive[p] = alive[p] = 0, cnt_alive--;
                break;
            }
        }
    }

    for(auto a : ans){
        visited[a] = 0;
        cout << a << " ";
    }
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}