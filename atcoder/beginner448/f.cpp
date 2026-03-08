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

const int MAXW = 2e7 + 10;

int calc_b(int n){
    int a;
    for(a = 1; a*a <= n; a++);
    return MAXW / a;
}

void solve(){
    int n;
    cin >> n;

    vector<tuple<int, int, int>> v(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        v[i] = {x, y, i};
    }

    int B = calc_b(n);
    sort(v.rbegin(), v.rend());

    int prev = -1;
    int fst = -1;
    int lst = -1;
    vector<int> go(n);
    for(int i = 0; i <= MAXW / B; i++){        
        int r = (i+1) * B;        

        vector<tuple<int, int, int>> tmp;
        while(sz(v) and get<0>(v.back()) < r){
            tmp.push_back(v.back());
            v.pop_back();
        }

        sort(tmp.begin(), tmp.end(), [](tuple<int, int, int> &a, tuple<int, int, int> &b){
            auto [xa, ya, ia] = a;
            auto [xb, yb, ib] = b;
            if(ya != yb) return ya < yb;
            return xa < xb;
        });

        if(i % 2){
            for(int j = 0; j < sz(tmp); j++){
                auto [x, y, idx] = tmp[j];
                if(prev == -1){
                    fst = idx;
                } else{
                    go[prev] = idx;
                }
                prev = idx;
                lst = idx;
            }
        } else{
            for(int j = sz(tmp) - 1; j >= 0; j--){
                auto [x, y, idx] = tmp[j];
                if(prev == -1){
                    fst = idx;
                } else{
                    go[prev] = idx;
                }
                prev = idx;
                lst = idx;
            }
        }
    }
    go[lst] = fst;

    vector<int> ans;    
    int curr = 0;
    while(sz(ans) < n){
        ans.push_back(curr+1);
        curr = go[curr];
    }

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}