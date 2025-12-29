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
        string s;
        cin >> s;

        int cnt= 0;
        int n = sz(s);

        if(s[0] == 'u') s[0] = 's', cnt++;
        if(s[n-1] == 'u') s[n-1] = 's', cnt++;

        for(int i = 1; i < n-1; i++){
            if(s[i] == 'u' and s[i+1] == 'u'){
                s[i+1] = 's';
                cnt++;
            }
        }
        
        cout << cnt << endl;
    }


    signed main(){
        darvem;
        int t = 1;
        cin >> t;

        while(t--) solve();
    }