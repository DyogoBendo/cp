#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double
#define int long long

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

void solve(){
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> v(n);
    vector<int> h(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v[i] = {x, i+1};
        h[i] = x;
    }

    if(m > n/2){        
        cout << -1 << endl;
        return;
    }


    sort(v.begin(), v.end());    
    sort(h.begin(), h.end());    

    // quero ver se m for 0 se eu consigo gerar 0

    if(m == 0){
        vector<pair<int, int>> actions;
        for(int i = 0; i < n - 1; i++){
            if(h[n-1] <= h[n-2]){                
                actions.push_back({v[i].second, v[i+1].second});
                h[i+1] -= v[i].first;
            } else{
                actions.push_back({v[i].second, v[n-1].second});
                h[n-1] -= v[i].first;
            }
        }        

        if(h[n-1] > 0){
            cout << -1 << endl;
            return;
        } 

        cout << sz(actions) << endl;
        for(auto a : actions) cout << a.first << " " << a.second << endl;        
        return;
    }

    int curr = 0;
    vector<pair<int, int>> actions;    
    while(((n - curr) / 2 > m) or ((n - curr) % 2)){
        actions.push_back({v[curr].second, v[curr+1].second});
        curr++;
    }    

    int tot = (n - curr) / 2 ;

    for(int i = curr; i < curr + tot; i++){
        actions.push_back({v[n-(i - curr) - 1].second, v[i].second});
    }

    cout << sz(actions) << endl;
    for(auto a : actions) cout << a.first << " " << a.second << endl;        
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}