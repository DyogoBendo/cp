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
    int n;
    cin >> n;
    vector<string> names (n);
    vector<int> is_set (n);
    vector<ld> mn (n, 1e9), mx (n, -1);
    string s;
    getline(cin, s);
    for (int i=0; i<n; i++){
        getline(cin, s);
        dbg(s);
        string a="";
        string b="";
        bool found=false;
        for (auto c: s){
            if (c == ' ') found = true;
            else if (found) b += c;
            else a += c;
        }
        dbg(a, b);
        names[i] = a;
        if (!b.empty()) mn[i] = mx[i] = stold(b), is_set[i] = 1;
    }

    ld cmn=0;
    ld tot=0;
    for (int i=n-1; i>=0; i--){
        if (is_set[i]) cmn = mn[i];
        mn[i] = cmn;
        tot += mn[i];
    }

    ld cmx=100;
    int ceq=0;
    for (int i=0; i<n; i++){
        if (is_set[i]) ceq = 0, cmx = mx[i];
        else ceq++;
        dbg(i, ceq, tot, mn[i], mx[i]);
        mx[i] = min(cmx, (100-(tot-mn[i]*ceq))/ceq);
        dbg(i, mx[i]);
    }

    cmx=100;
    tot=0;
    vector<ld> mxx (n);
    for (int i=0; i<n; i++){
        if (is_set[i]) cmx = mx[i];
        tot += cmx;
        mxx[i] = cmx;
    }

    ceq=0;
    for (int i=n-1; i>=0; i--){
        if (is_set[i]){
            tot += ceq*mx[i];
            ceq = 0;
        }
        else ceq++, tot -= mxx[i];
        dbg(i, ceq, tot, mn[i], mx[i]);
        mn[i] = max(mn[i], (100-tot)/ceq);
        dbg(i, mn[i]);
    }

    cout << setprecision(13) << fixed;
    for (int i=0; i<n; i++) if (!is_set[i]) cout << names[i] << ' ' << mn[i] << ' ' << mx[i] << '\n';
}

signed main(){
    fastio;
    int cases = 1;

    for (int i = 0; i < cases; i++)
    {
        solution();
    }
    
}