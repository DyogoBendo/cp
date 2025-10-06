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

int n;
const int INF = 100;

vector<pair<int, int>> ans;

int get(vector<int> x){
    if(x.empty()) return INF;
    return x.back();
}

void solve(vector<vector<int>> &v, int la, int lb){    
    if(v[0].empty() and v[1].empty() and v[2].back() == 1) return;
    int a, b;
    int ma = 0, mb = INF+1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){      
            if(get(v[j]) <= get(v[i])) continue;
            if(i == lb and j == la) continue;
            
            if(get(v[i]) == 1 and ma <= 1 and get(v[j]) % 2 == 0 and get(v[j]) < mb){
                ma = 1;
                mb = get(v[j]);
                a = i;
                b = j;
            } else if (get(v[i]) > 1){
                ma = get(v[i]);
                a = i;
                b = j;
            }                
        }
    }
    ans.push_back({a+1, b+1});    
    v[b].push_back(get(v[a]));
    v[a].pop_back();
    solve(v, a, b);
}

signed main(){
    darvem;

    cin >> n;

    vector<vector<int>> v(3);
    for(int i = n; i > 1; i--) v[0].push_back(i);
    ans.push_back({1, n%2 + 2});
    v[n%2 + 1].push_back(1);
    solve(v, 1, n%2 + 1);

    cout << sz(ans) << endl;
    for(auto a : ans) cout << a.first << " " << a.second << endl;
}