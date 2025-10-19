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

void setIO(string s) {	
	freopen((s + ".out").c_str(), "w", stdout);
}

void print(int ans){
    cout << "Case #"<<testcase << ": " << ans << endl;
}

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> current(n);
    vector<int> desired(n);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        current[i] = {x, i};
    } 
    for(int i = 0; i < n; i++) cin >> desired[i];

    sort(current.begin(), current.end());

    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++){
        auto [x, idx] = current[i];
        int d = desired[idx];        
        if(d < x){
            print(-1);
            return;
        }
        if(d > x){
            int change = lower_bound(current.begin(), current.end(), make_pair(d, -1)) - current.begin();            
            if(change == n){
                print(-1);
                return;
            }            
            if(current[change].first != d){                
                print(-1);
                return;
            }
            ans.push_back({idx+1, current[change].second+1});
        }
    }

    print(sz(ans));
    for(auto [i, j] : ans) cout << i << " " << j << endl;
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