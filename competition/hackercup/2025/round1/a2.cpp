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
int testcase = 0;
int n;

void setIO(string s) {	
	freopen((s + ".txt").c_str(), "w", stdout);
}

void print(int ans){
    cout << "Case #"<<testcase << ": " << ans << endl;
}

int check(vector<int> &v, int x){
    vector<int> starts;
    for(int i = 0; i < n; i++){
        if(v[i] <= x) starts.push_back(i);        
    }
    
    vector<int> visited(n);
    for(auto s : starts){        
        if(visited[s]) continue;
        visited[s] = 1;
        for(int i = s; i > 0; i--){
            if(visited[i-1]) break;
            if(abs(v[i-1] - v[i]) <= x) visited[i-1] = 1;
            else break;
        }
        
        for(int i = s; i < n-1; i++){
            if(visited[i+1]) break;
            if(abs(v[i+1] - v[i]) <= x) visited[i+1] = 1;
            else break;
        }
    }
    
    int cnt= 0;
    for(int i = 0; i < n; i++) cnt += visited[i];    
    return cnt == n;
}

void solve(){
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int lo = 0, hi = 1e9+7;

    while(lo < hi){
        int m = (hi - lo) / 2 + lo;
        if(check(v, m)) hi = m;
        else lo = m + 1;
    }

    print(hi);
}

int main(){
	darvem;
    setIO("output");
    int t;
    cin >> t;
    while(t--){
        testcase++;
        solve();
    }
}