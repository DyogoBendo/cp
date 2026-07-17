#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) a.size())
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do {cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solution(){
    int n,l,r;
    cin >> n >> l >> r;

    vector<int> notes(n);
    for(auto &x : notes) cin >> x;

    vector<int> oct(n);

    for (int i = 0; i < n; i++)
    {
        if(l <= notes[i] && notes[i] <= r) {
            oct[i] = 0;
            continue;
        }

        if(notes[i] < l){
            int x = l - notes[i];
            int y = x/12;

            if(y*12 + notes[i] >= l) oct[i] = y;
            else oct[i] = y+1;
        }

        if(notes[i] > r){
            int x = notes[i] - r;
            int y = x/12;

            if(-(y*12) + notes[i] <= r) oct[i] = -y;
            else oct[i] = -(y+1);
        }
    }
    
    int last = -1e9, cur = 0, mn = 1e9;
    for(auto x : oct) {
        if(last == -1e9) {
            last = x;
            cur = 1;
            continue;
        }

        if(last == x) {
            cur++;
        } else {
            mn = min(mn, cur);
            cur = 1;
        }

        last = x;
    }

    mn = min(cur, mn);

    cout << mn << endl;
}

signed main(){
    int cases = 1;

    for (int i = 0; i < cases; i++)
    {
        solution();
    }
    
}