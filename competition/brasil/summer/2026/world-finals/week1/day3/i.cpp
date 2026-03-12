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
    int n;
    cin >> n;

    int r = n % 10;
    int k = n / 10;

    int special_base[5] = {0, 2, 4, 6, 8};
    
    for (int j = 0; j < r; ++j) {
        for (int p = 0; p < 5; ++p) {
            cout << (special_base[p] + j) % 10;
        }
        cout << endl;
    }
    
    int decades_output = 0;
    for (int i = 0; i < 10000; ++i) {
        if (decades_output == k) break;

        int c1 = (i / 1000) % 10;
        int c2 = (i / 100) % 10;
        int c3 = (i / 10) % 10;
        int c4 = i % 10;

        if (r > 0 && c1 == 2 && c2 == 4 && c3 == 6 && c4 == 8) {
            continue;
        }
        
        for (int j = 0; j < 10; ++j) {
            cout << j
                 << (c1 + j) % 10
                 << (c2 + j) % 10
                 << (c3 + j) % 10
                 << (c4 + j) % 10 << "\n";
        }
        decades_output++;
    }
}