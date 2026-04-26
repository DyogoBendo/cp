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
    int n, a, b;
    cin >> n >> a >> b;

    if(n&1 or ((a+b) & 1) == 0){
        cout << "No" << endl;
        return;
    }

    string ans = "";
    string base_row = "";
    for(int i = 0; i < n-1; i++) base_row += "R";
    base_row += "D";
    for(int i = 0; i < n-1; i++) base_row += "L";
    base_row += "D";

    int cnt_rows = 0;
    while(a > 2){
        a -= 2;
        ans += base_row;
        cnt_rows += 2;
    }

    string base_column = "DRUR";
    int cnt_columns = 0;
    while(b > 2){
        b -= 2;
        ans += base_column;
        cnt_columns += 2;
    }

    dbg(ans, a, b);

    if(a == 1 and b == 2){
        ans += "DR";
    } else{
        ans += "RD";
    }

    cnt_rows += 2;
    cnt_columns += 2;

    reverse(base_column.begin(), base_column.end());
    for(int i = cnt_columns; i < n; i+= 2){
        ans += base_column;
    }

    reverse(base_row.begin(), base_row.end());
    for(int i = cnt_rows; i < n; i+= 2) ans += base_row;

    cout << "Yes" << endl << ans << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}