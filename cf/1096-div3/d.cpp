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
        int n;
        cin >> n;

        vector<int> v(2*n);
        for(int i = 0; i < 2*n; i++) cin >> v[i];

        int pos0_l = -1, pos0_r = -1;
        for(int i = 0; i < 2*n; i++){
            if(v[i] == 0){
                if(pos0_l == -1) pos0_l = i;
                else pos0_r = i;
            }
        }

        auto check = [&](int l, int r){
            int j = 0;
            for(int i = l; i <= r; i++){
                if(v[i] != v[r - j]) return 0;
                j++;
            }

            vector<int> ap;
            for(int i = l; i <= (r + l) / 2; i++) ap.push_back(v[i]);

            l--, r++;
            while(l >= 0 and r < 2*n){
                if(v[l] == v[r]) ap.push_back(v[l]);
                else break;
                l--, r++;
            }

            sort(ap.begin(), ap.end());

            int prev = -1;

            int ans = 0;
            for(auto x : ap){
                if(x == prev + 1) ans++, prev = x;
                else return ans;
            }
            return ans;
        };

        dbg(pos0_l, pos0_r);

        cout << max({check(pos0_l, pos0_l), check(pos0_l, pos0_r), check(pos0_r, pos0_r)}) << endl;

    }


    signed main(){
        darvem;
        int t = 1;
        cin >> t;

        while(t--) solve();
    }