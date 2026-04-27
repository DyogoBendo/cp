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

signed main(){
    darvem;

    int n, d;
    cin >> n >> d;

    vector<vector<int>> v(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v[x].push_back(i);
    }

    for(int i = 0; i < n; i++){
        bool possible = true;
        int l = 0, r = d-1;
        bool first = true;
        //cout << "---------------" << endl;
        for(int x : v[i]){
            dbg(l, r, x);
            if(first or x - l < d){
                dbg("a");
                r = max(r, x);
                if(first) l = x;
            } else{
                if(x - r > d){
                    dbg("b");
                    l = x;
                    r = max(x, r + 2*d);
                } else{
                    dbg("c");
                    possible = false;
                }
            }
            first = false;
        }

        if(possible){
            cout << i << endl;
            return 0;
        }
    }

    cout << n << endl;
    return 0;
}