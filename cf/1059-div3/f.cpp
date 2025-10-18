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

int n, m;
bool check_0(vector<int> &ans, vector<int> &visited, vector<int> &v_min, vector<int> &v_max){
    for(int i = 1; i <= n; i++){
        if(visited[i] == m){            
            int prev = 1;
            for(int j = 0; j < n; j++){
                if(j == i-1) ans[j] = prev = 0;
                else ans[j] = j + prev;
            } 
            return true;
        }
    }
    return false;
}

bool check_unvisited(vector<int> &ans, vector<int> &visited, vector<int> &v_min, vector<int> &v_max){
    for(int i = 1; i <= n; i++){
        if(visited[i] == 0){            
            int prev = 1;
            for(int j = 0; j < n; j++){
                if(j == i-1) ans[j] = prev = 0;
                else ans[j] = j + prev;
            } 
            return true;
        }
    }
    return false;
}

bool check_side(vector<int> &ans, vector<int> &visited, vector<int> &v_min, vector<int> &v_max){
    for(int i = 1; i <= n; i++){
        if(v_min[i] < i or v_max[i] > i){               
            if(v_min[i] < i) ans[i-2] = 1;
            else ans[i] = 1;            
            ans[i-1] = 0;

            int x = 2;            
            for(int j = 0; j < n; j++){
                if(j == i-1 or ans[j])continue;
                ans[j] = x;
                x++;
            } 
            return true;
        }
    }
    return false;
}


void solve(){
    cin >> n >> m;

    vector<pair<int, int>> intervals(m);
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;

        intervals[i] = {l, r};
    }
    
    vector<int> visited(n+1), vmin(n+1, 1), vmax(n+1, n);
    for(int i = 0; i < m; i++){
        auto [l, r] = intervals[i];
        for(int a= l; a <= r; a++){
            visited[a]++;            
            vmin[a] = max(vmin[a], l);
            vmax[a] = min(vmax[a], r);
        } 
    }

    vector<int> ans(n);

    if(!check_0(ans, visited, vmin, vmax) && !check_side(ans, visited, vmin, vmax) && !check_unvisited(ans, visited, vmin, vmax)){
        ans[0] = 0;
        ans[n-1] = 1;
        for(int i = 1; i < n-1; i++) ans[i] = i+1;
    }

    for(auto a : ans) cout << a << ' ';
    cout << endl;
    
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}