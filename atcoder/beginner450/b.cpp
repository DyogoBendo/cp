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

const int MAXN = 110;
ll m[MAXN][MAXN];

signed main(){
    darvem;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) cin >>m[i][j];

    bool found = false;

    for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) for(int k = j+1; k < n; k++) found |= (m[i][j] + m[j][k]) < m[i][k];

    cout << (found ? "Yes": "No") << endl;

}