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

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> p(n);
    set<string> st;
    for(int i = 0; i < n; i++){
        string s, t;        
        t.resize(m);        
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            x--;
            t[x] = '0' + j;
            s += '0' + x;
        }
        for(int j = 0; j < m; j++){            
            st.insert(t.substr(0, j+1));
        }
        p[i] = s;
    }    

    for(int i = 0; i < n; i++){
        int ans = 0;
        for(int j = 0; j < m; j++){           
            string look = p[i].substr(0, j+1);  

            if(st.count(look)) ans = j + 1;
            else break;
        }
        cout << ans << " ";
    }
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}